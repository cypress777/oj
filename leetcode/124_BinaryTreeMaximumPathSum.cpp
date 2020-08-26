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
    int max_val = 0;

    int helper(TreeNode* root) {
        // cout << "---- " << root->val << endl;
        int cur_val = root->val;

        int l_val = 0, r_val = 0;
        if (root->left != NULL) l_val = max(l_val, helper(root->left));
        if (root->right != NULL) r_val = max(r_val, helper(root->right));

        max_val = max(max_val, cur_val + l_val + r_val);
        cur_val += max(l_val, r_val);
        // cout << "---- " << root->val << " " << cur_val << " " << max_val << endl;
        return cur_val;
    }

    int maxPathSum(TreeNode* root) {
        max_val = root->val;
        helper(root);

        return max_val;
    }
};
