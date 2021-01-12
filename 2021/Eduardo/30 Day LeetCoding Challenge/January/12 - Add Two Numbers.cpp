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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int r = l1->val+l2->val;
        ListNode *res = new ListNode(r%10);
        r/=10;
        
        l1 = l1->next; l2 = l2->next;
        
        ListNode *aux = res;
        while(l1 != NULL && l2 != NULL){
            int v = l1->val + l2->val + r;
            
            aux->next = new ListNode(v%10);
            r = v/10;
            
            aux = aux->next; l1 = l1->next; l2 = l2->next;
        }
        
        while(l1 != NULL){
            int v = l1->val + r;
            
            aux->next = new ListNode(v%10);
            r = v/10;
            
            aux = aux->next; l1 = l1->next;
        }
        
        while(l2 != NULL){
            int v = l2->val + r;
            
            aux->next = new ListNode(v%10);
            r = v/10;
            
            aux = aux->next; l2 = l2->next;
        }
        
        if(r != 0)
            aux->next = new ListNode(r);
        
        return res;
    }
};