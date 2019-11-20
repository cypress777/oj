/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<TreeNode*> queue = {root};
        vector<int> levels = {0};
        int f = 0, r = 0;

        vector<vector<int>> res;

        while (r >= f) {
            TreeNode *node = queue[f];
            int l = levels[f];
            f++;

            if (node == NULL) continue;

            if (l >= res.size()) res.push_back({});

            res[l].push_back(node->val);

            while (r + 2 >= queue.size()) queue.push_back(NULL);
            while (r + 2 >= levels.size()) levels.push_back(0);

            queue[r + 1] = node->left;
            levels[r + 1] = l + 1;

            queue[r + 2] = node->right;
            levels[r + 2] = l + 1;

            r = r + 2;
        }

        return res;
    }
};
