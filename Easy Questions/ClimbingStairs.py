# Iterative Solution with constant space

class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1: return 1
        if n == 2: return 2
        
        prev1 = 1
        prev2 = 2
        for i in range(3, n + 1):
            steps = prev1 + prev2
            prev1 = prev2
            prev2 = steps
            
        return steps
        

# Iterative solution with dynamic programming

class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1:
            return 1
        
        dp = [0] * (n + 1)
        dp[1] = 1
        dp[2] = 2
        for i in range(3, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]
            
        return dp[n]
        

# Faster version with memoization:

class Solution(object):
    def countClimbs(self, i, n):
        if i > n:
            return 0
        if i == n:
            return 1
        if self.memo[i] > 0:
            return self.memo[i]
        self.memo[i] = self.countClimbs(i + 1, n) + self.countClimbs(i + 2, n)
        return self.memo[i]
        
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        self.memo = [0] * n
        return self.countClimbs(0, n)

# Initial super slow recursive solution:

class Solution(object):
    def countClimbs(self, i, n):
        if i > n:
            return 0
        if i == n:
            return 1
        return self.countClimbs(i + 1, n) + self.countClimbs(i + 2, n)
    
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        return self.countClimbs(0, n)