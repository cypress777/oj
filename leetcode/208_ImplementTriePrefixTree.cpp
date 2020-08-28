class Node {
public:
    vector<Node *> nexts{26, nullptr};
    bool is_end = false;
    
    Node() {}
};

class Trie {
public:
    /** Initialize your data structure here. */
    Node *root = nullptr;
    
    Trie() {
        root = new Node;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *cur = root;
        
        for (int i = 0; i < word.size(); i++) {
            int id = word[i] - 'a';
            
            if (cur->nexts[id] == nullptr) {
                Node *next = new Node;
                cur->nexts[id] = next;
                cur = next;
            } else {
                cur = cur->nexts[id];
            }
            
            if (i == word.size() - 1) cur->is_end = true;
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *cur = root;
        
        for (int i = 0; i < word.size(); i++) {
            int id = word[i] - 'a';
            
            if (cur->nexts[id] != nullptr) {
                cur = cur->nexts[id];
            } else {
                return false;
            }
            
            if (i == word.size() - 1) {
                if (!cur->is_end) return false;
            }
        }
        
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *cur = root;
        
        for (int i = 0; i < prefix.size(); i++) {
            int id = prefix[i] - 'a';
            
            if (cur->nexts[id] != nullptr) {
                cur = cur->nexts[id];
            } else {
                return false;
            }
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
