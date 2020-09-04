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
    TreeNode* findLCA(TreeNode *root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root == p || root == q) return root;

        TreeNode *leftLCA = findLCA(root->left, p, q);
        TreeNode *rightLCA = findLCA(root->right, p, q);

        if (leftLCA != nullptr && rightLCA != nullptr) return root;

        return (leftLCA == nullptr ? rightLCA : leftLCA);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findLCA(root, p, q);
    }
};
