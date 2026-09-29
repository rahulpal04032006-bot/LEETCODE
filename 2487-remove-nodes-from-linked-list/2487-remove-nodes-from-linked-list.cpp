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
ListNode* rev(ListNode* head){
    ListNode* prev = NULL;
    ListNode* curr = head;
    while(curr != NULL){
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;

}
    ListNode* removeNodes(ListNode* head) {
        ListNode* head1 = rev(head);
        int maxval = head1->val;
        ListNode* curr = head1;
       
        while(curr->next != NULL){
            if(curr->next->val < maxval){
               curr->next = curr->next->next;
            }else{
                curr = curr->next;
                maxval = curr->val;
            }
            
        }
       return rev(head1);
    }
};