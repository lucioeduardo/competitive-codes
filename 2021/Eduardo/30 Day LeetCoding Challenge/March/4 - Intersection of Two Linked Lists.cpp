/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n=0,m=0;
        
        ListNode *aux = headA;
        
        while(aux != NULL){
            n++;
            aux = aux->next;
        }
        
        aux = headB;
        
        while(aux != NULL){
            m++;
            aux = aux->next;
        }
        
        cout << n << " " << m << endl;
        
        while(n > m){
            headA = headA->next;
            n--;
        }
        
        while(m > n){
            headB = headB->next;
            m--;
        }
        
        while(headA!=NULL){
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }
};