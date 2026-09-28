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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slo = head;
        ListNode* fast = head;

        for(int i=0; i<n; i++){
            fast=fast->next;
        }

        if(!fast) {
            return head->next;
        }

        while(fast->next){
            slo=slo->next;
            fast=fast->next;
        }
        slo->next = slo->next->next;

        return head;
    }
};
