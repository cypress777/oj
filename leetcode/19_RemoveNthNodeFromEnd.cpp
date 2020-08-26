/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes;

        ListNode *p = head;
        while (p != NULL) {
            nodes.push_back(p);
            p = p->next;
        }

        if (n == nodes.size()) return head->next;

        nodes[nodes.size() - n - 1]->next = nodes[nodes.size() - n]->next;

        return head;
    }
};
