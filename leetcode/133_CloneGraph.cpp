#include<vector>;
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

vector<Node*> copies;

Node* dfs(Node* node) {
    auto copy = new Node();
    copy->val = node->val;
    copies[node->val] = copy;

    for (auto neighbor : node->neighbors) {
        if (copies[neighbor->val] == nullptr) {
            copy->neighbors.push_back(dfs(neighbor));
        } else {
            copy->neighbors.push_back(copies[neighbor->val]);
        }
    }

    return copy;
}

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        copies = vector<Node*>(110, nullptr);

        return dfs(node);
    }
};