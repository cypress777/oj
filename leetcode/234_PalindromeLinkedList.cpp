/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;

        ListNode *tail = head;
        int size = 1;
        while (tail->next != nullptr) {
            size++;
            tail = tail->next;
        }
        
        ListNode *p = head;
        for (int i = 0; i < (size + 1) / 2; i++) {
            p = p->next;
        }
        ListNode *last = nullptr;
        ListNode *cur = p;
        while(cur != nullptr) {
            ListNode *next = cur->next;
            cur->next = last;
            last = cur;
            cur = next;
        }
        
        while (tail != nullptr) {
            if (tail->val != head->val) return false;
            tail = tail->next;
            head = head->next;
        }
        return true;
    }
};
