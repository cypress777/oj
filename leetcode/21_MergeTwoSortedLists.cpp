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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        ListNode *p1 = NULL, *p2 = NULL, *head = NULL, *cur = NULL;

        if (l1->val <= l2->val) {
            head = l1;
            p1 = l1->next;
            p2 = l2;
        } else {
            head = l2;
            p1 = l1;
            p2 = l2->next;
        }
        cur = head;

        while (p1 != NULL || p2 != NULL) {
            if (p1 == NULL) {
                cur->next = p2;
                break;
            }

            if (p2 == NULL) {
                cur->next = p1;
                break;
            }

            if (p1->val <= p2->val) {
                cur->next = p1;
                p1 = p1->next;
            } else {
                cur->next = p2;
                p2 = p2->next;
            }

            cur = cur->next;
        }

        return head;
    }
};
