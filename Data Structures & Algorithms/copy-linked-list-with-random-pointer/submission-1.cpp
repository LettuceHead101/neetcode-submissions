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
        unordered_map<Node*, Node*> oldToNew;
        oldToNew[nullptr] = nullptr;

        Node* current = head;
        // first pass create the nodes with regular next pointers
        while(current != nullptr) {
            Node* temp = new Node(current->val);
            oldToNew[current] = temp;
            current = current->next;
        }

        // second pass point the nodes to their random points
        current = head;
        while(current != nullptr) {
            Node* temp = oldToNew[current];
            temp->next = oldToNew[current->next];
            temp->random = oldToNew[current->random];

            current = current->next;
        }

        return oldToNew[head];
    }
};
