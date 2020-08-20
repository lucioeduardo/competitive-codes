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
    vector<ListNode*> nodes;
    
    void build(ListNode* node){
        if(node == NULL) return;
        
        nodes.push_back(node);
        build(node->next);
    }
    
    void reorderList(ListNode* head) {
        build(head);
        int n = nodes.size();
        
        for(int i=0; i<n/2; i++){
            nodes[n-i-2]->next = NULL;
            nodes[n-i-1]->next = nodes[i]->next;
            nodes[i]->next = nodes[n-i-1];
        }
        
        //nodes[n-1]->next = NULL;
    }
};