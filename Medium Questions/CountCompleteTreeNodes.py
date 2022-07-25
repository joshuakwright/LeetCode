//Sometimes slightly faster solution with binary search

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def exists(self, idx, height, node):
        left, right = 0, 2**height - 1;
        for i in range(height):
            pivot = left + (right - left) // 2
            if idx <= pivot:
                node = node.left
                right = pivot
            else:
                node = node.right
                left = pivot + 1
        return node is not None
    
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        
        height = 0
        prev = root

        while prev.left is not None:
            prev = prev.left
            height += 1
        if(height == 0):
            return 1
        
        left, right = 1, 2**height - 1
        while left <= right:
            pivot = left + (right - left) // 2
            if self.exists(pivot, height, root):
                left = pivot + 1
            else:
                right = pivot - 1
        
        return (2**height - 1) + left

//My Initial semi fast working solution:

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def countBottomRow(self, root, cheight, maxheight):
        nodeCount = 0
        
        if cheight == maxheight: 
            return 1
        if root.left is not None:
            nodeCount += self.countBottomRow(root.left, cheight + 1, maxheight)
        else: 
            return nodeCount
        if root.right is not None:
            nodeCount += self.countBottomRow(root.right, cheight + 1, maxheight)
        else:
            return nodeCount
        
        return nodeCount
    
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        
        heightl = 1
        heightr = 1
        nodes = 0
        
        prev = root
        while prev.left is not None:
            prev = prev.left
            heightl += 1
        prev = root
        while prev.right is not None:
            prev = prev.right
            heightr += 1
        if heightl == heightr: 
            return 2**heightl - 1
        
        bottomNodeCount = self.countBottomRow(root, 1, heightl)
        
        return (2**heightr - 1) + bottomNodeCount
    
    