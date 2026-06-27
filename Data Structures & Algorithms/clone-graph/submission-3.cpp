/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // if we're given a nullptr then return it
        if(!node) return nullptr;

        // keep track  of the old to new nodes
        unordered_map<Node*, Node*> otn;
        // queue that holds all of our unprocessed nodes
        queue<Node*> q;
        
        // initialize the queue with our starting root node
        otn[node] = new Node(node->val);
        q.push(node);

        while(!q.empty()) {
            // get the front of the queue
            Node* curr = q.front();
            q.pop();

            // process all of its neighbors
            for(Node* neighbor : curr->neighbors) {
                //check if it's in our map yet
                if(otn.find(neighbor) == otn.end()) {
                    otn[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                
                otn[curr]->neighbors.push_back(otn[neighbor]);
            }
        }

        return otn[node];
    }
};
