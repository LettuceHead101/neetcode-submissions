class TrieNode {
public: 
    shared_ptr<TrieNode> children[26];

    // TrieNode* children[26];

    bool endOfWord;

    TrieNode() {
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        endOfWord = false;
    }

};



class PrefixTree {
public:
    // TrieNode* root;
    shared_ptr<TrieNode> root;

    PrefixTree() {
        // root = new TrieNode();
         root = make_shared<TrieNode>();
    }
    
    void insert(string word) {
        shared_ptr<TrieNode> current = root;
        
        for(char c : word) {
            int i = c - 'a';
            if(current->children[i] == nullptr) {
                current->children[i] = make_shared<TrieNode>();
            }
            current = (current)->children[i];
        }

        current->endOfWord = true;
    }
    
    bool search(string word) {
        shared_ptr<TrieNode>  current = root;

        for(char c : word) {
            int i = c - 'a';
            if(current->children[i] == nullptr) {
                return false;
            }
            current = current->children[i];
        }
        return current->endOfWord;
    }
    
    bool startsWith(string prefix) {
        shared_ptr<TrieNode>  current = root;

        for(char c : prefix) {
            int i = c - 'a';
            if(current->children[i] == nullptr) {
                return false;
            }
            current = current->children[i];
        }
        return true;
    }

    
};
