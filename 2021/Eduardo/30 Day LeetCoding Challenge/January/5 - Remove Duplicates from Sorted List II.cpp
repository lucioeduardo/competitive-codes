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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        
        ListNode* no = head, *aux, *res=NULL, *last=NULL;
        
        int prev = -200;
        
        while(no != NULL){
            aux = no->next;
            
            if(no->val != prev && ( aux == NULL || no->val != aux->val)){
                if(res == NULL) {
                    res = no;
                    last = res;
                }
                else{
                    last->next = new ListNode(no->val);
                    last = last->next;
                }
            }
            
            prev = no->val;
            no = no->next;
            
        }
        
        if(last != NULL) last->next = NULL;
        
        return res;
    }
};