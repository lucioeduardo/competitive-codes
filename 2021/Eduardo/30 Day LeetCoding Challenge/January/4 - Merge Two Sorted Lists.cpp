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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res, *it;
        
        if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        else{
            if(l1->val < l2->val){
                res = new ListNode(l1->val);
                l1 = l1->next;
            }else{
                res = new ListNode(l2->val);
                l2 = l2->next;
            }
            
            it = res;
            
            while(l1 != NULL && l2 != NULL){
                if(l1->val < l2->val){
                    it->next = new ListNode(l1->val);
                    l1 = l1->next;
                }else{
                    it->next = new ListNode(l2->val);
                    l2 = l2->next;
                }
                
                it = it->next;
            }
            
            while(l1 != NULL){
                it->next = new ListNode(l1->val);
                l1 = l1->next;
                it = it->next;
            }
            
            while(l2 != NULL){
                it->next = new ListNode(l2->val);
                l2 = l2->next;
                it = it->next;
            }
                
        }
        
        
        return res;
    }
};