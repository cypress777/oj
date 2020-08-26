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
    int get_min_id(const vector<ListNode*> &curs) {
        int min_id = -1;
        int min_val = -1;

        for (int i = 0; i < curs.size(); i++) {
            if (curs[i] != NULL && (min_id < 0 || curs[i]->val < min_val)) {
                min_id = i;
                min_val = curs[i]->val;
            }
        }

        return min_id;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> curs = lists;
        ListNode *head = NULL, *p = NULL;

        int id = get_min_id(curs);
        while (id >= 0) {
            if (head == NULL) {
                head = curs[id];
                p = curs[id];
            } else {
                p->next = curs[id];
                p = p->next;
            }

            curs[id] = curs[id]->next;
            id = get_min_id(curs);
        }

        return head;
    }
};
