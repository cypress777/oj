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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        vector<TreeNode*> stack = {root};
        vector<int> vst = {-1};
        int p = 0;

        while (p >= 0) {
            TreeNode *cur = stack[p];
            if (cur == NULL) {
                p--;
                continue;
            }

            if (cur->left != NULL && vst[p] == -1) {
                vst[p] = 1;

                if (p + 1 < stack.size()) {
                    stack[p + 1] = cur->left;
                    vst[p + 1] = -1;
                } else {
                    stack.push_back(cur->left);
                    vst.push_back(-1);
                }
                p++;
            } else {
                res.push_back(cur->val);

                if (cur->right != NULL) {
                    stack[p] = cur->right;
                    vst[p] = -1;
                } else {
                    p--;
                }
            }
        }

        return res;
    }
};
