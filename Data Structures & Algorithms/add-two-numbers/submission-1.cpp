/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(-1);
        ListNode* current = result;
        int carryover = 0;

        while(l1 || l2 || carryover != 0) {
            int num1 = 0;
            int num2 = 0;

            if(l1 != nullptr) {
                num1 = l1->val;
                l1 = l1->next;
            } 
            if(l2 != nullptr) {
                num2 = l2->val;
                l2 = l2->next;
            }

            int sum = num1 + num2;

            if(carryover != 0) {
                sum += carryover;
            } else {
                sum += carryover;
            }

            carryover = sum / 10;
            sum = (sum >= 10) ? sum - 10 : sum;

            current->next = new ListNode(sum);
            current = current->next;
        }

        return result->next;
    }
};
