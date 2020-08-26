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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode*> stack_a;
        vector<ListNode*> stack_b;

        ListNode *p = headA;
        while (p != NULL) {
            stack_a.push_back(p);
            p = p->next;
        }

        p = headB;
        while (p != NULL) {
            stack_b.push_back(p);
            p = p->next;
        }

        int top_a = stack_a.size() - 1, top_b = stack_b.size() - 1;
        ListNode *res = NULL;

        while (top_a >= 0 && top_b >= 0) {
            if (stack_a[top_a] == stack_b[top_b]) res = stack_a[top_a];
            else break;

            top_a--;
            top_b--;
        }

        return res;
    }
};
