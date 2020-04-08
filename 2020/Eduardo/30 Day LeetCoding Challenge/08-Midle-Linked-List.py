# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def middleNode(self, head):
        qtd=1
        aux = head
        
        while(aux.next != None):
            qtd += 1;
            aux = aux.next;
        
        for i in range((qtd)/2):
            head = head.next
        
        return head
        """
        :type head: ListNode
        :rtype: ListNode
        """
        