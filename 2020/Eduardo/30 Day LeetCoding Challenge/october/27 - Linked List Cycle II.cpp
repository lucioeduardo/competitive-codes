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
    
    set<ListNode*> seen;
    
    Solution(){
        seen.clear();
    }
    
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return head;
        
        seen.insert(head);
        
        if(seen.count(head->next))
            return head->next;
        
        return detectCycle(head->next);
    }
};