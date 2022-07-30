# Fast solution with constant memory

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
            return None
        
        hare = tortoise = head
        while hare is not None and hare.next is not None:
            hare = hare.next.next
            tortoise = tortoise.next
            if hare == tortoise:
                break
        
        if hare is None or hare.next is None:
            return None
        
        start = head
        intersect = hare
        
        while start != intersect:
            start = start.next
            intersect = intersect.next
            
        return start
        