/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        // Both pointers begin at the head.
        ListNode* slow = head;
        ListNode* fast = head;

        // Moving fast by two nodes is safe only when both
        // fast and the node after fast are non-null.
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            // Compare node addresses, not their stored values.
            // Meeting at the same node proves that a cycle exists.
            if (slow == fast) {
                return true;
            }
        }

        // If fast reaches the end, the list is acyclic.
        return false;
    }
};