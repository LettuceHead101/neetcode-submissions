/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/




class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp_head = head;
        Node* dummy = new Node(0);
        Node* dummy_curr = dummy;

        while(temp_head){
            dummy_curr->next = new Node(temp_head->val);
            dummy_curr = dummy_curr->next;
            dummy_curr->random = temp_head->random;
            temp_head->random = dummy_curr;
            temp_head = temp_head->next;
        }
        dummy_curr->next = nullptr;

        dummy_curr = dummy;
        temp_head = head;

        while(dummy_curr){
            dummy_curr->random = (dummy_curr->random != nullptr) ? dummy_curr->random->random : nullptr;
            dummy_curr = dummy_curr->next;
            temp_head = temp_head->next;

        }
        dummy = dummy->next;
        return dummy;
    }
};




