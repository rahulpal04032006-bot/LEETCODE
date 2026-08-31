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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL){
            return {-1,-1};
        }
        vector<int>ans;
        ListNode*prev = head;
        ListNode*curr = head->next;
        int idx = 1;
        while(curr->next != NULL){
            ListNode*next = curr->next;
            if((curr->val > prev->val && curr->val > next->val) || (curr->val < prev->val && curr->val < next->val)){
                ans.push_back(idx);
            }
            prev = curr;
            curr = next;
            idx++;
        }
        if(ans.size() < 2){
            return {-1,-1};
        }
        int min1 = INT_MAX;
        for(int i=1;i<ans.size();i++){
            min1 = min(min1,ans[i] - ans[i-1]);
        }
        int max1 = ans.back() - ans.front();
        return {min1,max1};
    }
};