class TrieNode {
public: 
    TrieNode* children[26];
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
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* current = root;
        
        for(char c : word) {
            int i = c - 'a';
            if(current->children[i] == nullptr) {
                current->children[i] = new TrieNode();
            }
            current = current->children[i];
        }

        current->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* current = root;

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
        TrieNode* current = root;

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
