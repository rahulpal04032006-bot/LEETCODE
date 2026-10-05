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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;
        int sum = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while(curr != NULL){
            if(curr->val == 0){
                dummy->next = new ListNode(sum);
                dummy = dummy->next;
                sum = 0;
              
            }else
            sum += curr->val;
            curr = curr->next;
        }
        return tail->next;
    }
};