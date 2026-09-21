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

void merge(vector<ListNode*>& lists,int st,int mid,int end){
    ListNode dummy(0);
ListNode* tail = &dummy; 
    ListNode* left = lists[st];
    ListNode* right = lists[mid+1];
    while(left != NULL && right != NULL){
        if(left->val <= right->val){
            tail->next = left;
            left = left->next;
        }else{
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }
    while(left != NULL){
        tail->next = left;
        left = left->next;
        tail = tail->next;
    }
    while(right != NULL){
        tail->next = right;
        right = right->next;
        tail = tail->next;
    }
    lists[st] = dummy.next;
}
void mergesort(vector<ListNode*>& lists,int st,int end){
    if(st >= end){
        return;
    }
    int mid = st + (end - st)/2;
    mergesort(lists,st,mid);
    mergesort(lists,mid+1,end);
    merge(lists,st,mid,end);
}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return NULL;
        }
        mergesort(lists,0,lists.size()-1);
        return lists[0];
    }
};