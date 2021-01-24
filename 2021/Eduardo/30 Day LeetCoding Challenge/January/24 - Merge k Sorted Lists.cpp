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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *res = NULL;
        ListNode *aux = NULL;
        
        while(true){
            int m=-1;
            
            for(int i=0; i<lists.size(); i++){
                ListNode* node = lists[i];
                if(node == NULL) continue;
                
                if(m == -1 || node->val < lists[m]->val)
                    m=i;
            }
            
            if(m == -1) break;
            
            int v = lists[m]->val;
            
            if(res == NULL){
                res = new ListNode(v);
                aux = res;
            }else{
                aux->next = new ListNode(v);
                aux = aux->next;
            }
            
            lists[m] = lists[m]->next;
                
        }
        
        return res;
    }
};