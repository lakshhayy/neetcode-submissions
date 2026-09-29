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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;

        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* ptr = dummy;

        while(p1 || p2 || carry){
            int val = carry;
            
            if(p1){
                val = val + p1->val;
                p1=p1->next;
            }
            if(p2){
                val = val + p2->val;
                p2=p2->next;
            }
            int sum = val % 10;
            carry = val/10;

            ptr->next = new ListNode(sum);
            ptr=ptr->next;
        }
        return dummy->next;
    }
};
