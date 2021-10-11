struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    TreeNode* findSuccessor(TreeNode* root) {
        TreeNode* next = root->right;
        while (next && next->left) next = next->left;
        return next;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        
        if(!root->left || !root->right) {
            return root->left? root->left : root->right;
        }

        auto next = findSuccessor(root);
        root->val = next->val;
        root->right = deleteNode(root->right, next->val);
        
        return root;
    }
};