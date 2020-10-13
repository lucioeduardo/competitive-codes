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
    ListNode* sortList(ListNode* head) {
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        
        ListNode *slow = head, *fast=head->next;
        
        while(fast != NULL){
            fast = fast->next;
            
            if(fast != NULL){
                slow = slow->next;
                fast = fast->next;
            }
        }
        
        ListNode *itA=head, *itB=slow->next;
        
        
        itB = sortList(itB);
        slow->next = NULL;
        itA = sortList(itA);
        
        ListNode *res;
        
        if(itA == NULL) res=itB;
        else if(itB == NULL) res = itA;
        else{
            if(itA->val <= itB->val){
                res = itA;
                itA = itA->next;
            }
            else{
                res = itB;
                itB = itB->next;
            }
            
            ListNode *it = res;
            
            while(itA != NULL || itB != NULL){
                if(itA == NULL){
                    it->next = itB;
                    itB = itB->next;
                }else if(itB == NULL){
                    it->next = itA;
                    itA = itA->next;
                }else if(itA->val <= itB->val){
                    it->next = itA;
                    itA = itA->next;
                }else{
                    it->next = itB;
                    itB = itB->next;
                }
                it = it->next;
            }
        }        
        
    
        return res;    
    }
    
};