/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        unordered_map<Node*,Node*>m;
        Node* newhead = new Node(head->val);
        Node* old = head->next;
        Node* newh = newhead;
        m[head] = newhead;
        while(old != NULL){
            Node* currNode = new Node(old->val);
            newh->next = currNode;
            m[old] = currNode;
            old = old->next;
            newh = newh->next;
        }
        Node* oldh = head;
        Node* newhe = newhead;
        while(oldh != NULL){
            newhe->random = m[oldh->random];
            newhe = newhe->next;
            oldh = oldh->next;
        }
        return newhead;
    }
};