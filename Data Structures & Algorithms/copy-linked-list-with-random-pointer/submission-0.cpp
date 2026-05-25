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
        // Map old nodes to newly allocated copy nodes
        unordered_map<Node*, Node*> oldToCopy;
        
        // Explicitly handle nullptr mapping for dead ends
        oldToCopy[nullptr] = nullptr;

        // First pass: create deep copies of nodes on the heap
        Node* curr = head;
        while(curr != nullptr) {
            // Allocate on the heap so nodes persist outside the loop
            Node* copy = new Node(curr->val);
            oldToCopy[curr] = copy;
            curr = curr->next;
        }

        // Second pass: connect the next and random pointers
        curr = head;
        while(curr != nullptr) {
            Node* copy = oldToCopy[curr];
            // Safely look up the corresponding copied nodes
            copy->next = oldToCopy[curr->next];
            copy->random = oldToCopy[curr->random];
            curr = curr->next;
        }

        return oldToCopy[head];
    }
};
