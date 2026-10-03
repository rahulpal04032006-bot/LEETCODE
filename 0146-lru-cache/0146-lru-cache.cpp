class LRUCache {
public:


class Node{
    public:
    int key,val;
    Node* next;
    Node* prev; 
    Node(int k,int v){
        key = k;
        val = v;
        next = prev = NULL;
    }
};
Node* head = new Node(-1,-1);
Node* tail = new Node(-1,-1);
unordered_map<int,Node*>m;
int limit;

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void delNode(Node* oldNode){
    Node* oldprev = oldNode->prev;
    Node* oldnext = oldNode->next;
    oldprev->next = oldnext;
    oldnext->prev = oldprev;
}

void addNode(Node* newNode){
    Node* oldNode = head->next;
    head->next = newNode;
    newNode->prev = head;
    
    newNode->next = oldNode;
    oldNode->prev = newNode;
    
}
    
    int get(int key) {
       if(m.find(key) == m.end()){
        return -1;
       } 
       Node* oldans = m[key];
       int ans = oldans->val;
       
       delNode(oldans);
       addNode(oldans);
       m[key] = oldans;
       return ans;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* oldNode = m[key];
            delNode(oldNode);
            m.erase(key);
            delete oldNode;
        }
        if(limit == m.size()){
            Node* oldNode = tail->prev;
            m.erase(oldNode->key);
            delNode(oldNode);
        }
        Node* newNode = new Node(key,value);
        addNode(newNode);
        m[key] = newNode;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */