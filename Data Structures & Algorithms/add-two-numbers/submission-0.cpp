class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2, 0);
    }

    ListNode* add(ListNode* l1, ListNode* l2, int carryover = 0) {
        if (!l1 && !l2 && carryover == 0) {
            return nullptr;
        }

        int val1 = l1 ? l1->val : 0;
        int val2 = l2 ? l2->val : 0;
        
        int sum = val1 + val2 + carryover;
        
        ListNode* newNode = new ListNode(sum % 10);
        
        ListNode* next1 = l1 ? l1->next : nullptr;
        ListNode* next2 = l2 ? l2->next : nullptr;
        
        newNode->next = add(next1, next2, sum / 10);

        return newNode;
    }
};