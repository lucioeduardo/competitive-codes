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
    int res;
    
    int solve(ListNode *node){
        if(node == NULL) return 0;
        
        int qtd = solve(node->next);
        res += (1<<qtd)*node->val;
        
        return qtd+1;
    }
    
    int getDecimalValue(ListNode* head) {
        res = 0;
        solve(head);
        
        return res;
    }
};
