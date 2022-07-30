# Fastest solution using a slow and fast pointer

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        fast = slow = head
        while fast is not None:
            fast = fast.next
            if fast is not None: 
                fast = fast.next
            else: 
                break
            slow = slow.next
            
        return slow



# Possibly slower but better spacially solution:
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        length = 0
        temp = head
        while temp is not None:
            length += 1
            temp = temp.next
            
        for i in range(length / 2):
            head = head.next
            
        return head



# Initial spacially bad solution

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        record = []
        while head is not None:
            record.append(head)
            head = head.next
            
        return record[len(record) / 2]