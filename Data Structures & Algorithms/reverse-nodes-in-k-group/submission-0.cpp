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
    ListNode* rev(ListNode* head, int k) {
        int cnt = 0;

        if(head == NULL || head->next == NULL){
            return NULL;
        }

        ListNode* temp = head;
        ListNode* prev = NULL;

        while(cnt < k && temp){
            ListNode* nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
            cnt++;
        }
        head->next = reverseKGroup(temp,k);
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* temp = head;
        int cnt = 0;
        while(temp && cnt < k){
            temp = temp->next;
            cnt++;
        }
        if(cnt < k){
            return head;
        }
        return rev(head, k);
    }
};
