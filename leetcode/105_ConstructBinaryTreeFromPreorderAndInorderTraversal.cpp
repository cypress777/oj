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
    unordered_map<int, int> lut;

    TreeNode* helper(const vector<int>& preorder, const vector<int>& inorder,
                     int pre_start, int pre_end, int in_start, int in_end) {
        if (pre_start > pre_end || in_start > in_end) return NULL;

        TreeNode *root = new TreeNode(preorder[pre_start]);

        int root_pos = lut[preorder[pre_start]];
        // cout << pre_start << " " << pre_end << " " << in_start << " " << in_end << endl;
        // cout << preorder[pre_start] << " " << root_pos << endl;

        int l_len = root_pos - in_start;
        int r_len = in_end - root_pos;

        int lps = pre_start + 1;
        int lpe = lps + l_len - 1;

        int rps = lpe + 1;
        int rpe = rps + r_len - 1;

        root->left = helper(preorder, inorder, lps, lpe, in_start, root_pos - 1);
        root->right = helper(preorder, inorder, rps, rpe, root_pos + 1, in_end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) lut[inorder[i]] = i;

        TreeNode *root = helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);

        return root;
    }
};
