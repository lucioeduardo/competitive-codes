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
    ListNode* rotateRight(ListNode* head, int k) {
        int size=1;
        
        ListNode *node = head;
        if(node == NULL) return node; 
        
        while(node->next != NULL){
            size++;
            node = node->next;
        }
        
        k %= size;
                
        if(k == 0) return head;
        
        node = head;
        
        
        for(int i=0; i<(size-k)-1; i++)
            node = node->next;
        
        ListNode *last = node;
        
        while(last->next != NULL) last = last->next;
        
        last->next = head;
        ListNode *newHead = node->next;
        node->next = NULL;
        
        return newHead;
    }
};