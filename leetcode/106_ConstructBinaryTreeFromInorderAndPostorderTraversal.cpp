#include<vector>
#include<unordered_map>
using namespace std;

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
    void build(
        TreeNode* root,
        const vector<int>& inorder,
        const vector<int>& postorder,
        const unordered_map<int, int>& position,
        int in_start, 
        int in_end,
        int post_start,
        int post_end) {
        int root_val = postorder[post_end];
        root->val = root_val;
        int in_root_pos = position.at(root_val);

        int left_size = in_root_pos - in_start;
        int right_size = in_end - in_root_pos;
        
        // cout << "---- " << endl;
        // cout << in_start << " " << in_end << endl;
        // cout << post_start << " " << post_end << endl;
        // cout << root_val << " " << in_root_pos << endl;
        // cout << left_size << " " << right_size << endl;
        
        if (left_size > 0)
        {
            auto left_root = new TreeNode();
            root->left = left_root;
            build(
                left_root,
                inorder,
                postorder,
                position,
                in_start,
                in_start + left_size - 1,
                post_start,
                post_start + left_size - 1);
        }
        
        if (right_size > 0) {
            int right_in_start = in_root_pos + 1;
            int right_post_start = post_start + left_size;
            auto right_root = new TreeNode();
            root->right = right_root;
            build(
                right_root,
                inorder,
                postorder,
                position,
                right_in_start,
                right_in_start + right_size - 1,
                right_post_start,
                right_post_start + right_size - 1);
        }
    };

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int N = inorder.size();
        unordered_map<int, int> position;

        for (int i = 0; i < N; i++) position.insert({inorder[i], i});

        auto root = new TreeNode();
        build(root, inorder, postorder, position, 0, N - 1, 0, N - 1);
        return root;
    }
};
