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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(0);
        ListNode *p = l1, *q = l2;
        ListNode *cur = res;
        int carry = 0;

        while (p != NULL || q != NULL) {
            int a = (p == NULL ? 0 : p->val);
            int b = (q == NULL ? 0 : q->val);

            int sum = a + b + carry;
            cur->val = sum % 10;
            carry = sum / 10;

            if (p != NULL) p = p->next;
            if (q != NULL) q = q->next;

            if (p != NULL || q != NULL) {
                cur->next = new ListNode(0);
                cur = cur->next;
            }
        }

        if (carry > 0) {
            cur->next = new ListNode(carry);
        }

        return res;
    }
};