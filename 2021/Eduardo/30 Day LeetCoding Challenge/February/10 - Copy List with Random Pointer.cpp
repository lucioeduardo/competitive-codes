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
        if(head == NULL) return NULL;
        map<Node*, Node*> pts;
        
        Node* res = new Node(head->val), *aux = res;
        Node* no=head->next;
        
        pts[head]=res;
        res->random = head->random;
        
        while(no != NULL){
            aux->next = new Node(no->val);
            pts[no]=aux->next;
            
            
            aux = aux->next;
            aux->random = no->random;
            
            no = no->next;
            
        }
        
        aux->next = NULL;
        
        aux = res;
        
        while(aux != NULL){
            aux->random = pts[aux->random];
            aux = aux->next;
        }
        
        return res;
    }
};