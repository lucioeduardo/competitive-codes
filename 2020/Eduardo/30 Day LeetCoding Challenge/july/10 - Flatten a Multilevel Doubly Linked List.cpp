/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    
    Node* end;
    
    void solve(Node* node){        
        end = node;
        
        Node* aux = node->next;
                
        if(node->child != NULL){
            node->next = node->child;
            node->next->prev = node;
            solve(node->child);
        }
        
        
        if(aux != NULL){
           aux->prev = end; 
           end->next = aux; 
           solve(end->next);
        }
        
        node->child = NULL;
    } 
    
    Node* flatten(Node* head) {
        if(head == NULL) return head;
           
        solve(head);
        
        return head;
        
    }
};