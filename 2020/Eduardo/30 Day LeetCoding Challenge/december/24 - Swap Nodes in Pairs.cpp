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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* no = head, *sec;
        
        head = head->next;
    
        while(no != NULL){
            sec = no->next;
            
            if(sec == NULL) break;
            
            ListNode* aux = sec->next;
            sec->next = no;
            no->next = (aux == NULL || aux->next == NULL) ? aux : aux->next;
                        
            no = aux;
        }
        
        return head;
    }
    
    
};