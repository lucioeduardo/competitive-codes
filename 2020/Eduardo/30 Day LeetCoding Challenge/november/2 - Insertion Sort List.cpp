
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
    
    
    void insert(ListNode *head){
        
    }
    
    ListNode* insertionSortList(ListNode* head) {
        ListNode *sorted = NULL;
        
        while(head != NULL){
            ListNode *aux = sorted;
            
            //cout << head->val << endl;
            
            if(sorted == NULL || head->val < sorted->val){
                sorted = head;
                head = head->next;
                sorted->next = aux;
            }else{
                while(aux->next != NULL && aux->next->val < head->val) aux = aux->next;
                ListNode* aux2 = aux->next;
                aux->next = head;
                head = head->next;
                aux->next->next = aux2;
            }
        }
        
        return sorted;
    }
};
