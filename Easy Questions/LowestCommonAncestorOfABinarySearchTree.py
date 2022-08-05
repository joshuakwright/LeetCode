# iterative solution without a stack:

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        while root:
            if root.val <= p.val and root.val >= q.val:
                return root
            elif root.val >= p.val and root.val <= q.val:
                return root
            
            if root.val > p.val:
                root = root.left
            else:
                root = root.right
        

# Iterative solution:

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        stack = [root]
        while stack:
            root = stack.pop()
            if root.val <= p.val and root.val >= q.val:
                return root
            elif root.val >= p.val and root.val <= q.val:
                return root
            
            if root.val > p.val:
                stack.append(root.left)
            else:
                stack.append(root.right)
        

# Initial Recursive solution

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if root.val >= p.val and root.val <= q.val:
            return root
        elif root.val <= p.val and root.val >= q.val:
            return root
        
        if root.val < p.val:
            return self.lowestCommonAncestor(root.right, p, q)
        else:
            return self.lowestCommonAncestor(root.left, p, q)
        