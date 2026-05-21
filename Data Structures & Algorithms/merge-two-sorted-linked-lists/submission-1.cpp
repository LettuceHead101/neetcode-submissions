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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2 == nullptr) return list1;
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        ListNode* newhead = nullptr;
        ListNode* current = nullptr;

        while(list1 != nullptr && list2 != nullptr) {

            //does newhead point to anything for the first time?
            if(newhead == nullptr) {
                if(list1->val <= list2->val) {
                    newhead = list1;
                    current = newhead;
                    list1 = list1->next;
                    continue;
                } else {
                    newhead = list2;
                    current = newhead;
                    list2 = list2->next;
                    continue;
                }
            }

            // just add and put stuff to the next of the list
            if(list1->val <= list2->val) {
                current->next = list1;
                current = current->next;
                list1 = list1->next;
            } else {
                current->next = list2;
                current = current->next;
                list2 = list2->next;
            }
        }

        // add remaining nodes
        if (list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }


        return newhead;
    }
};
