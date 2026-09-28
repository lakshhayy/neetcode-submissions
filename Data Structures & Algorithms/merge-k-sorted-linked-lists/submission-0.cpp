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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>,                    
        greater<pair<int,ListNode*>>> pq;

        for(auto it : lists){
            if(it){
                pq.push({it->val, it});
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(!pq.empty()){
            ListNode* curr = pq.top().second;
            pq.pop();

            temp->next = curr;
            temp = curr;
            
            if(curr->next){
                pq.push({curr->next->val, curr->next});
            }
        }

        return dummy->next;
    }
};
