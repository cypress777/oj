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
    bool ldr(TreeNode* root, int &low, int &high) {
        if (root == NULL) return true;

        low = root->val;
        high = root->val;

        TreeNode *l = root->left;
        TreeNode *r = root->right;

        if (l != NULL) {
            int ll, lh;
            if (!ldr(l, ll, lh)) return false;
            if (lh >= root->val) return false;
            low = min(ll, low);
        }

        if (r != NULL) {
            int rl, rh;
            if (!ldr(r, rl, rh)) return false;
            if (rl <= root->val) return false;
            high = max(rh, high);
        }

        return true;
    }

    bool isValidBST0(TreeNode* root) {
        int l, h;
        return ldr(root, l, h);
    }

};
