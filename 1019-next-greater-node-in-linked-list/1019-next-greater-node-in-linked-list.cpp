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
int size(ListNode* head){
    int x = 0;
    while(head != NULL){
        x++;
        head = head->next;
    }
    return x;
}
    vector<int> nextLargerNodes(ListNode* head) {
        int n = size(head);
        vector<int>ans(n,0);
        stack<int>st;
        vector<int>curr;
        while(head != NULL){
            curr.push_back(head->val);
            head = head->next;
        }
        st.push(curr[n-1]);
        for(int i = n-2;i>=0;i--){
            while(!st.empty() && st.top() <= curr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = 0;
            }else{
                ans[i] = st.top();
            }
            st.push(curr[i]);
        }
       return ans;
    }
};