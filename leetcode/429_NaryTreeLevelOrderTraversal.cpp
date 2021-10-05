#include<vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return vector<vector<int>>{};
        
        vector<Node*> queue;
        vector<int> levels;
        int start = 0, end = -1;

        queue.push_back(root);
        levels.push_back(0);
        end++;

        while (start <= end) {
            auto cur = queue[start];
            int cur_level = levels[start];
            start++;

            for (auto child : cur->children) {
                if (child != nullptr) {
                    // cout << child->val << " " << cur_level + 1 << endl;
                    queue.push_back(child);
                    levels.push_back(cur_level + 1);
                    end++;
                }
            }
        }

        vector<vector<int>> result{};
        int last_level = -1;
        for (int i = 0; i < queue.size(); i++) {
            int val = queue[i]->val;
            int lev = levels[i];
            // cout << val << " " << lev << endl;
            if (lev != last_level) {
                result.push_back(vector<int>{});
            }

            result[lev].push_back(val);
            last_level = lev;
        }

        return result;
    }
};