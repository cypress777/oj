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
    bool is_mirrow(TreeNode* a, TreeNode *b) {
        if (a == NULL && b == NULL) return true;
        if (a == NULL || b == NULL) return false;

        if (a->val != b->val) return false;

        if (a->left != NULL || b->right != NULL) {
            if (a->left == NULL || b->right == NULL) return false;
            if (!is_mirrow(a->left, b->right)) return false;
        }


        if (a->right != NULL || b->left != NULL) {
            if (a->right == NULL || b->left == NULL) return false;
            if (!is_mirrow(a->right, b->left)) return false;
        }

        return true;
    }

    // recursive
    bool isSymmetric0(TreeNode* root) {
        if (root == NULL) return true;
        return is_mirrow(root->left, root->right);
    }

    // iterative
    bool isSymmetric1(TreeNode* root) {
        if (root == NULL) return true;

        vector<TreeNode*> queue = {root->left, root->right};
        int p = 1;
        while (p >= 0) {
            if (p % 2 != 1) return false;

            TreeNode *a = queue[p];
            TreeNode *b = queue[p - 1];
            p = p - 2;

            if (a == NULL && b == NULL) continue;
            if (a == NULL || b == NULL) return false;

            if (a->val != b->val) return false;

            while (p + 4 >= queue.size()) {
                queue.push_back(NULL);
            }

            queue[p + 1] = a->left;
            queue[p + 2] = b->right;
            queue[p + 3] = a->right;
            queue[p + 4] = b->left;

            p += 4;
        }

        return true;
    }
};
