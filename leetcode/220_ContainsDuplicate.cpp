#include<vector>
#include<algorithm>
using namespace std;


struct TreeNode
{
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    int val;

    TreeNode(int val) {
        this->val = val;
    }
};

struct BST
{
    TreeNode* _root = nullptr;
    BST(const vector<int>& nums, size_t k) {
        int len = min(k, nums.size());
        for (int i = 0; i < len; i++) {
            insert(nums[i]);
        }
    }

    void insert(int val) {
        _root = _insert(_root, val);
    }

    TreeNode* _insert(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }

        if (root->val <= val) {
            root->right = _insert(root->right, val);
        } else {
            root->left = _insert(root->left, val);
        }
        return root;
    }

    void remove(int val) {
        _root = _remove(_root, val);
    }

    TreeNode* _remove(TreeNode* root, int val) {
        if (!root) return root;
        
        if (root->val < val) {
            root->right = _remove(root->right, val);
            return root;    
        }
        if (root->val > val) {
            root->left = _remove(root->left, val);
            return root;
        }
        
        if (!root->left || !root->right) return root->left ? root->left : root->right;

        auto next = _successor(root, val);
        root->val = next->val;
        root->right = _remove(root->right, next->val);
        return root;
    }

    TreeNode* _successor(TreeNode* root, int val) {
        auto cur = root->right;

        while (cur->left) {
            cur = cur->left;
        }

        return cur;
    }

    bool find_range(long long num, long long rng) {
        return _find_range(_root, num, rng);
    }

    bool _find_range(TreeNode* root, long long num, long long rng) {
        if (!root) return false;

        if (abs(root->val - num) <= rng) {
            return true;
        }

        if (root->val > num) return _find_range(root->left, num, rng);
        return _find_range(root->right, num, rng);
    }
};


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k == 0) return false;
        auto tree = BST(nums, k);

        for (int i = 0; i < nums.size(); i++) {
            tree.remove(nums[i]);
            if (i + k < nums.size()) tree.insert(nums[i + k]);
            
            if (tree.find_range(nums[i], t)) return true;
        }

        return false;
    }
};