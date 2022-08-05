# My initial fast breadth first solution

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root is None: 
            return []
        
        output, queue = [], [root, ]
        oListIndex = 0
        while queue:
            output.append([])
            for i in range(len(queue)):
                root = queue.pop(0)
                output[oListIndex].append(root.val)
                if root.left is not None:
                    queue.append(root.left)
                if root.right is not None:
                    queue.append(root.right)
            oListIndex += 1
            
        return output

# Depth first solution:

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def dfs(self, root, oList, level):
        if root is None:
            return
        if len(oList) <= level:
            oList.append([])
        
        oList[level].append(root.val)
        if root.left is not None:
            self.dfs(root.left, oList, level + 1)
        if root.right is not None:
            self.dfs(root.right, oList, level + 1)
        
    
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        outputList = []
        self.dfs(root, outputList, 0)
        
        return outputList
                
                