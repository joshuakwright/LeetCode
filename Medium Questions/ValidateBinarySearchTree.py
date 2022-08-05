# Iterative in order traversal

# Recursive in order traversal:

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):    
    def inOrder(self, root):
        if not root:
            return True
        
        if not self.inOrder(root.left):
            return False
        if root.val <= self.prev:
            return False
        self.prev = root.val
        return self.inOrder(root.right)
                
    
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        self.prev = float('-inf')
        return self.inOrder(root)

# Stack based DFS:

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):    
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        
        stack = [(root, float('-inf'), float('inf'))]
        while stack:
            root, lower, upper = stack.pop()
            if not root:
                continue
            if root.val <= lower or root.val >= upper:
                return False
            stack.append((root.right, root.val, upper))
            stack.append((root.left, lower, root.val))
            
        return True

# Initial recursive DFS solution:

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isBST(self, root, low=float('-inf'), high=float('inf')):        
        if root is None:
            return True
        
        if root.val <= low or root.val >= high:
            return False
        
        return (self.isBST(root.right, root.val, high) and self.isBST(root.left, low, root.val))
    
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        return self.isBST(root)