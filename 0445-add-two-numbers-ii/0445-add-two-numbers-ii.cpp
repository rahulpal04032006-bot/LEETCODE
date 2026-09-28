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
    ListNode* next = head;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
return prev;
}
ListNode* sum(ListNode* head1,ListNode* head2){
   ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;
    int carry = 0;
    while(head1 != NULL || head2 != NULL || carry != 0){
       int val = carry;
      if(head1 != NULL){
        val += head1->val;
        head1 = head1->next;
      }
        if(head2 != NULL){
        val += head2->val;
        head2 = head2->next;
      }
      int digit = val % 10;
      carry = val / 10;
      tail->next = new ListNode(digit);
      tail = tail->next;
    }
    ListNode* ans = dummy->next;
    delete dummy;
    return rev(ans);
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head1 = rev(l1);
    ListNode* head2 = rev(l2);
    return sum(head1,head2);        
    }
};