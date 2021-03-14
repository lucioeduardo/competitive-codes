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
    ListNode* swapNodes(ListNode* head, int k) {
        int n=0;
        
        ListNode* no = head;
        
        while(no!=NULL){
            n++;
            no = no->next;
        }
        
        ListNode *a = head;
        ListNode *b = head;
        
        for(int i=0; i<k-1; i++){
            a = a->next;
        }
        
        for(int i=0; i<n-k; i++){
            b = b->next;
        }
        
        swap(a->val,b->val);
        
        return head;
    }
};