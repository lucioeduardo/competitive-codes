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
        stack<int> q1,q2;
        
        while(l1 != NULL){
            q1.push(l1->val);
            l1 = l1->next;
        }
        
        while(l2 != NULL){
            q2.push(l2->val);
            l2 = l2->next;
        }
        
        ListNode* res = NULL;
        int r=0;
        
        
        
        while(!q1.empty() && !q2.empty()){
            ListNode* aux = res;
            
            int a = q1.top(); q1.pop();
            int b = q2.top(); q2.pop();
            
            cout << a<< " " << b << " " << r << endl;
            
            res = new ListNode((a+b+r)%10);
            res->next = aux;
            
            r = (a+b+r) >= 10;
        }
        
        while(!q1.empty()){
            ListNode* aux = res;
            int a = q1.top(); q1.pop();
            
            res = new ListNode((a+r)%10);
            res->next = aux;
            r = (a+r) >= 10;
        }
        
        while(!q2.empty()){
            ListNode* aux = res;
            int a = q2.top(); q2.pop();
            
            res = new ListNode((a+r)%10);
            res->next = aux;
            r = (a+r) >= 10;
        }
        
        if(r != 0){
            ListNode* aux = res;
            
            res = new ListNode(r);
            res->next = aux;
        }
        
        
        return res;
    }
};