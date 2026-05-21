#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // needed for std::reverse

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        // Edge case: if either number is zero, the product is zero
        if (num1 == "0" || num2 == "0") return "0";

        vector<string> additionArrays;
        string result = "";

        // traverse backwards through the num1 string
        for(int i = num1.size() - 1; i >= 0; i--) {
            // how many extra zeros do we need in our string given the x10 multiplier per number
            // Note: Changed num2 to num1 because the outer loop relies on num1
            int extraZeros = (num1.size() - 1) - i;

            // help us detect if we have a carryover
            int carryover = 0;

            // the string we're going to be tracking the multiplication in
            string currentMultiplication = "";

            while(extraZeros > 0) {
                // padds out the string with the extra needed zeros
                currentMultiplication += '0';
                extraZeros--;
            }

            // traverse backwards through the num2 string
            for(int j = num2.size() - 1; j >= 0; j--) {
                // get the first digit
                int digit1 = num1[i] - '0';

                // get the second digit
                int digit2 = num2[j] - '0';

                // multiply and save the result in digit1
                digit1 *= digit2;

                // add the carryover we have currently
                digit1 += carryover;

                // if we have anything to carryover again we calculate it here
                carryover = digit1 / 10;

                // get only the last digit of our new value
                digit1 = digit1 % 10;

                // add the new digit to our string
                currentMultiplication += digit1 + '0';
            }

            // if we still have a carryover then push that into the new string at the end again
            if(carryover != 0) currentMultiplication += carryover + '0';

            // push the calculated string into our array
            additionArrays.push_back(currentMultiplication);
        }

        // firstly we need to set the result to the first array
        result = additionArrays[0];

        // iterate through the arrays and add them to our result
        // Start at index 1 so we don't add additionArrays[0] twice
        for(int k = 1; k < additionArrays.size(); k++) {
            string s = additionArrays[k];
            string tempResult = "";
            int carry = 0;
            
            int p1 = 0; // pointer for result
            int p2 = 0; // pointer for the next string to add
            
            // Loop as long as we have digits in either string, or a lingering carry
            while(p1 < result.size() || p2 < s.size() || carry != 0) {
                int sum = carry;
                
                if(p1 < result.size()) {
                    sum += result[p1] - '0';
                    p1++;
                }
                if(p2 < s.size()) {
                    sum += s[p2] - '0';
                    p2++;
                }
                
                carry = sum / 10;
                tempResult += (sum % 10) + '0';
            }
            
            // Update result with the sum we just calculated
            result = tempResult; 
        }

        // Because we built everything from least significant digit to most
        // the whole string is currently backwards. We reverse it for the final answer
        reverse(result.begin(), result.end());

        return result;
    }
};