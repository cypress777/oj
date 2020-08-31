struct Node {
    vector<Node *> child;
    bool is_end;
    bool is_saved;
    
    Node() {
        child = vector<Node *>(26, nullptr);
        is_end = false;
        is_saved = false;
    }
};

class Solution {
public:
    vector<int> dw = {1, -1, 0, 0};
    vector<int> dh = {0, 0, 1, -1};
    vector<vector<char>> map;
    int bw, bh;
    vector<string> result;
    Node *trie;
    
    bool get_bit(long long state, int pos) {
        return ((state >> pos) & 1);
    }
    
    long long set_bit(long long state, int pos) {
        return (state |= (1UL << pos));
    }
    
    Node *build_trie(vector<string>& words) {
        Node *root = new Node;
        
        for (auto word : words) {
            Node *cur = root;
            for (int i = 0; i < word.size(); i++) {
                int id = word[i] - 'a';
                
                if (cur->child[id] == nullptr) {
                    auto new_node = new Node;
                    cur->child[id] = new_node;
                    cur = new_node;
                } else {
                    cur = cur->child[id];
                }
                if (i == word.size() - 1) cur->is_end = true;
            }
        }
        
        return root;
    }
    
    void bfs(long long state, Node *root, int cur_pos, string cur_word) {
        if (get_bit(state, cur_pos)) return;
        long long next_state = set_bit(state, cur_pos);

        int cur_h = cur_pos / bw, cur_w = cur_pos % bw;
        
        char cur_char = map[cur_h][cur_w];
        
        for (int i = 0; i < root->child.size(); i++) {
            Node *next_root = root->child[i];

            if (next_root == nullptr) continue;
            if (cur_char - 'a' != i) continue;
     
            string next_word = cur_word;
            next_word.push_back(cur_char);

            if (next_root->is_end && !next_root->is_saved) {
                result.push_back(next_word);
                next_root->is_saved = true;
            }
            
            for (int k = 0; k < 4; k++) {   
                int next_h= cur_h + dh[k], next_w = cur_w + dw[k], next_pos = next_h  * bw + next_w;
                
                if (next_h < 0 || next_h >= bh || next_w < 0 || next_w >= bw) continue;

                bfs(next_state, next_root, next_pos, next_word);
            }
        }
    }
    
    void search() {
        for (int i = 0; i < bh; i++) {
            for (int j = 0; j < bw; j++) {
                bfs(0, trie, i * bw + j, "");
            }
        }
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        map = board;
        bw = board[0].size();
        bh = board.size();
        
        trie = build_trie(words);
        
        if (trie != nullptr) search();
        
        return result;
    }
};
