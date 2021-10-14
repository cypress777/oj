#include<vector>

using namespace std;


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
    ListNode* remove_duplicate(ListNode* head) {
        if (!head || !head->next) return head;
        
        if (head->val == head->next->val) {
            auto cur = head->next;
            while(cur && cur->val == head->val) cur = cur->next;
            return remove_duplicate(cur);
        } else {
            head->next = remove_duplicate(head->next);
            return head;
        }
    }
    
    ListNode* deleteDuplicates(ListNode* head) {
        return remove_duplicate(head);
    }
};