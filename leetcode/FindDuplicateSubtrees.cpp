#include<vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int search(
        TreeNode* root,
        unordered_map<string, int>& tree_map,
        unordered_set<int>& added_node,
        vector<TreeNode*>& result
    ) {
        if (!root) return 0;
        
        int left_type = search(root->left, tree_map, added_node, result);
        int right_type = search(root->right, tree_map, added_node, result);
        
        auto cur_type = to_string(root->val) + "," + to_string(left_type) + "," + to_string(right_type);
        
        // cout << "----- " << root->val << " - " << cur_type << endl;
        
        int type_index;
        if (tree_map.find(cur_type) == tree_map.end()) {
            type_index = tree_map.size() + 1;
            tree_map.insert({cur_type, type_index});
        } else {
            type_index = tree_map[cur_type];
            
            if (added_node.find(type_index) == added_node.end()) {
                added_node.insert(type_index);
                result.push_back(root);
            }
        }
        
        // cout << type_index << endl;
        
        return type_index;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {    
        auto result = vector<TreeNode*>{};
        
        auto tree_map = unordered_map<string, int>{}; // "val,left_type,right_type"
        auto added_node =  unordered_set<int>{};
        
        search(root, tree_map, added_node, result);
        
        return result;
    }
};