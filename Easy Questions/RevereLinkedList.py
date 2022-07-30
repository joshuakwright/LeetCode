# My initial fast solution

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None or head.next is None: 
            return head
        
        prev = None
        temp = head.next
        while head.next is not None:
            head.next = prev
            prev = head
            head = temp
            temp = head.next
            
        head.next = prev
            
        return head

# Recursive version - uses way more space and is a bit slower

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None or head.next is None:
            return head
        
        nHead = self.reverseList(head.next)
        head.next.next = head
        head.next = None
            
        return nHead