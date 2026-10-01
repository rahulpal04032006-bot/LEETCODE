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
// int count =0;
// int size(ListNode* head){
//     ListNode* curr = head;
//     while(curr!=NULL){
//         count++;
//         curr = curr->next;
//     }
//     return count;
// }
    ListNode* deleteMiddle(ListNode* head) {
        // int n = size(head);
        // int x = n/2;
        // ListNode* temp = head;
        // ListNode* prev = NULL;
        // while(x > 0){
        //     prev = temp;
        //     temp = temp->next;
        //     x--;
        // }
        // prev->next = temp->next;
        // delete temp;
        // return head;
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        delete slow;
        return head;
        
    }
};