class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;

        for(int i = 0; i < tokens.size(); i++) {
            string token = tokens[i];

            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int num2 = numbers.top();
                numbers.pop();
                
                int num1 = numbers.top();
                numbers.pop();

                if (token == "+") {
                    numbers.push(num1 + num2);
                } else if (token == "-") {
                    numbers.push(num1 - num2);
                } else if (token == "*") {
                    numbers.push(num1 * num2);
                } else if (token == "/") {
                    numbers.push(num1 / num2);
                }
            } else {
                int num = stoi(token);
                numbers.push(num);
                continue;
            }
        }
        return numbers.top();
    }
};
