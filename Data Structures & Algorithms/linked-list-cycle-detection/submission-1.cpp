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
    bool hasCycle(ListNode* head) {
        if (head == nullptr) return false;

        unordered_set<ListNode*> seenNodes;
        int counter = 0;

        while(head != nullptr) {
            if(seenNodes.find(head) != seenNodes.end()) { // have we seen this node before?
                return true;
            }

            // add it to the list and traverse the list forward and increment counter
            seenNodes.insert(head);
            head = head->next;
            
        }

        return false;
    }
};
