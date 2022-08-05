# iterative dynamic but with linear space

# Iterative dynamic programming solution:

class Solution(object):  
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        memo = [[0] * n for i in range(m + 1)]
        memo[0][0] = 1
        for row in range(0, m):
            for col in range(0, n):
                up = memo[row - 1][col] if row - 1 >= 0 else 0
                left = memo[row][col - 1] if col - 1 >= 0 else 0
                if not (row == 0 and col == 0):
                    memo[row][col] = up + left
        
        return memo[m - 1][n - 1]

# much faster recursive solution with memoization

class Solution(object):
    def pathCount(self, m, n, row, col):
        if row > m or col > n:
            return 0
        
        if row == m and col == n:
            return 1
        
        if self.memo[row][col] != 0:
            return self.memo[row][col]
        
        self.memo[row][col] = self.pathCount(m, n, row + 1, col) + self.pathCount(m, n, row, col + 1)
        return self.memo[row][col]
        
    
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        
        self.memo = [[0] * n for i in range(m + 1)]
        return self.pathCount(m - 1, n - 1, 0, 0)

# Initial super slow version

class Solution(object):
    def pathCount(self, m, n, row, col):
        if row > m or col > n:
            return 0
        
        if row == m and col == n:
            return 1
        
        return self.pathCount(m, n, row + 1, col) + self.pathCount(m, n, row, col + 1)
        
    
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        return self.pathCount(m - 1, n - 1, 0, 0)