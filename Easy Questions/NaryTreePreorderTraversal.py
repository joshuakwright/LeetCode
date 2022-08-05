# Iterative version:

"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution(object):
    def preorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        if root is None:
            return []
        
        stack, output = [root, ], []
        while stack:
            root = stack.pop()
            output.append(root.val)
            stack.extend(root.children[::-1])
            
        return output



# Initial Recursive solution

"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution(object):
    def preTraverse(self, root, vals):
        if root is not None: 
            vals.append(root.val)
            for node in root.children:
                self.preTraverse(node, vals)
        else:
            return
    
    def preorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        preOrderList = []
        self.preTraverse(root, preOrderList)
        
        return preOrderList