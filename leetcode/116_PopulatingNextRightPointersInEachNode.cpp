/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return root;

        if (root->left != NULL) {
            root->left->next = root->right;
        }

        if (root->right != NULL) {
            if (root->next != NULL) root->right->next = root->next->left;
            else root->right->next = NULL;
        }

        if (root->left != NULL) connect(root->left);
        if (root->right != NULL) connect(root->right);

        return root;
    }
};
