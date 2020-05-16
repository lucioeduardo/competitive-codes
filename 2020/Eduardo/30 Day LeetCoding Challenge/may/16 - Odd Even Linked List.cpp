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
    
    
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return head;
        
        ListNode* firstEven = head->next;
        ListNode* firstOdd = head;
        
        ListNode* itEven = head->next;
        
        while(true){            
            if(firstOdd->next == NULL || firstOdd->next->next == NULL){
                firstOdd->next = firstEven;
                break;
            }else{
                firstOdd->next = firstOdd->next->next;
                itEven->next = itEven->next->next;
                
                firstOdd = firstOdd->next;
                itEven = itEven->next;
            }

        }
        
        
        return head;
    }
};