#include<vector>
#include<set>
using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
// class Solution {
// public:
//     TreeNode* findLCA(TreeNode *root, TreeNode* p, TreeNode* q) {
//         if (root == nullptr) return nullptr;
//         if (root == p || root == q) return root;

//         TreeNode *leftLCA = findLCA(root->left, p, q);
//         TreeNode *rightLCA = findLCA(root->right, p, q);

//         if (leftLCA != nullptr && rightLCA != nullptr) return root;

//         return (leftLCA == nullptr ? rightLCA : leftLCA);
//     }

//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         return findLCA(root, p, q);
//     }
// };

class Solution {
public:
    vector<TreeNode*> bfs_path(TreeNode* root, TreeNode* dest) {
        vector<TreeNode*> que;
        vector<int> last;
        que.push_back(root);
        last.push_back(-1);
        int front = 0, end = 0;

        while (front <= end) {
            auto cur_node = que[front];
            auto cur_index = front;

            if (cur_node == dest) break;

            front++;

            if (cur_node->left) {
                que.push_back(cur_node->left);
                last.push_back(cur_index);
                end++;
            }

            if (cur_node->right) {
                que.push_back(cur_node->right);
                last.push_back(cur_index);
                end++;
            }
        }

        vector<TreeNode*> path;
        int last_index = front;
        
        while (last_index >= 0) {
            auto last_node = que[last_index];
            path.push_back(last_node);
            
            last_index = last[last_index];
        }
        return path;
    };

    TreeNode* find_lca(
        const vector<TreeNode*>& path_a,
        const vector<TreeNode*>& path_b) {
            set<TreeNode*> set_b;
            for (auto node : path_b) set_b.insert(node);

            TreeNode* result;
            for (auto node : path_a) {
                if (set_b.find(node) != set_b.end()){
                    result = node;
                    break;
                }
            }
            return result;
    };

    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode* p, TreeNode* q) {
        auto path_p = bfs_path(root, p);
        auto path_q = bfs_path(root, q);
        return find_lca(path_p, path_q);
    }
};