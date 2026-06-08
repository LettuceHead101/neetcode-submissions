class TrieNode {
public:
    vector<TrieNode*> children;
    bool word;

    TrieNode() : children(26, nullptr), word(false) {}
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode;
    }
    
    void addWord(string word) {
        TrieNode* current = root;

        for(char c : word) {
            if(current->children[c - 'a'] == nullptr) {
                current->children[c - 'a'] = new TrieNode();
            }
            current = current->children[c - 'a'];
        }
        current->word = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

private:

    bool dfs(string word, int j, TrieNode* root) {
        TrieNode* current = root;

        for(int i = j; i < word.size(); i++) {
            char c = word[i];
            if(c == '.') {
                for(TrieNode* child : current->children) {
                    if(child != nullptr && dfs(word, i + 1, child)) {
                        return true;
                    }
                }
                return false;
            } else {
                if(current->children[c - 'a'] == nullptr) {
                    return false;
                }
                current = current->children[c - 'a'];
            }
        }
        return current->word;
    }
};
