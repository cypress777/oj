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
    void helper(ListNode *start, ListNode *end,
                ListNode *&new_start, ListNode *&new_end) {
        new_start = NULL, new_end = NULL;

        if (start == NULL || end == NULL) return;

        if (start == end) {
            new_start = start;
            new_end = end;
            return;
        }

        ListNode *m_start = start, *m_end = start;
        while (m_end->next != NULL &&
               m_end->next->val == m_end->val) m_end = m_end->next;

        ListNode *cur = m_end->next, *stop = end->next;
        ListNode *l_start = m_start, *l_end = NULL, *r_start = NULL, *r_end = m_end;

        while (cur != stop) {
            ListNode *tmp = cur->next;

            if (cur->val < start->val) {
                cur->next = l_start;
                if (l_end == NULL) l_end = cur;
                l_start = cur;
            } else {
                if (r_start == NULL) r_start = cur;
                r_end->next = cur;
                cur->next = NULL;
                r_end = cur;
            }

            cur = tmp;
        }

        new_start = m_start, new_end = m_end;
        ListNode *ls = NULL, *le = NULL, *rs = NULL, *re = NULL;

        helper(l_start, l_end, ls, le);
        helper(r_start, r_end, rs, re);

        if (ls != NULL && le != NULL) {
            le->next = m_start;
            new_start = ls;
        }
        if (rs != NULL && re != NULL) {
            m_end->next = rs;
            new_end = re;
        }

        new_end->next = NULL;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL) return NULL;

        ListNode *tail = head;
        while (tail->next != NULL) tail = tail->next;

        ListNode *new_head = NULL, *new_tail = NULL;
        helper(head, tail, new_head, new_tail);

        return new_head;
    }
};
