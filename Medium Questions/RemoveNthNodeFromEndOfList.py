// My initial fast solution

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        
        preHead = ListNode(-1)
        prev = preHead
        prev.next = head
        toChangeStart = 0
        
        while head is not None:
            if toChangeStart >= n:
                prev = prev.next
            toChangeStart += 1
            head = head.next
                
        prev.next = prev.next.next
        
        return preHead.next
        
        """
        preHead = ListNode(-1)
        prev = preHead
        
        prev.next = head
        head = head.next
        return preHead.next
        """
        
        
        
        
        
        
        
        
        
        
        
        