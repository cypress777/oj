/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        vector<Node*> nodes;
        unordered_map<Node*, int> id_tab;
        Node *p = head;
        while (p != NULL) {
            nodes.push_back(p);
            id_tab[p] = nodes.size() - 1;
            p = p->next;
        }

        vector<int> rand_ids(nodes.size(), -1);
        for (int i = 0; i < nodes.size(); i++) {
            Node *r = nodes[i]->random;
            if (r != NULL) rand_ids[i] = id_tab[r];
        }

        // for (int rid : rand_ids) cout << rid << " ";
        // cout << endl;

        Node *new_head = new Node(head->val, NULL, NULL);

        vector<Node*> new_nodes = {new_head};
        for (int i = 0; i < nodes.size() - 1; i++) {
            Node *next = new Node(nodes[i + 1]->val, NULL, NULL);
            new_nodes[i]->next = next;
            new_nodes.push_back(next);
        }

        for (int i = 0; i < new_nodes.size(); i++) {
            int id = rand_ids[i];
            // cout << "--- " << i << " " << new_nodes[i]->val << endl;

            if (id == -1) continue;

            new_nodes[i]->random = new_nodes[id];
            // cout << new_nodes[i]->random->val << endl;
        }

        return new_head;
    }
};
