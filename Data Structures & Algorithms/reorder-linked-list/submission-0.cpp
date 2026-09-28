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
    void reorderList(ListNode* head) {
        ListNode* slo = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slo=slo->next;
            fast=fast->next->next;
        }

        ListNode* curr = slo->next;
        slo->next = NULL;
        ListNode* prev = NULL;

        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        ListNode* p1 = head;
        ListNode* p2 = prev;

        while(p2){
            ListNode* t1 = p1->next;
            ListNode* t2 = p2->next;

            p1->next = p2;
            p2->next = t1;

            p1 = t1;
            p2 = t2;
        }
        
    }
};
