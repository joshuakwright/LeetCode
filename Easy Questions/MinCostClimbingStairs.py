# Linear time iterative version with constant space using bottom up DP

# Linear time iterative version using bottom up DP

class Solution(object):
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        memo = [0] * (len(cost) + 1)
        
        for i in range(2, len(cost) + 1):
            oneStep = memo[i - 1] + cost[i - 1]
            twoStep = memo[i - 2] + cost[i - 2]
            memo[i] = min(oneStep, twoStep)
            
        return memo[-1]

# Linear time recursive version using memoization

class Solution(object):
    def cheapestStep(self, cost, step):
        if step >= self.steps:
            return 0
        
        if self.memo[step] != -1:
            return self.memo[step]
        
        self.memo[step] = cost[step] + min(self.cheapestStep(cost, step + 1), self.cheapestStep(cost, step + 2))
        return self.memo[step]
    
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        self.steps = len(cost)
        self.memo = [-1] * self.steps
        return min(self.cheapestStep(cost, 0), self.cheapestStep(cost, 1))

# My initial super slow recursive version:

class Solution(object):
    def cheapestStep(self, cost, step):
        if step >= self.steps:
            return 0
        
        return cost[step] + min(self.cheapestStep(cost, step + 1), self.cheapestStep(cost, step + 2))
    
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        self.steps = len(cost)
        return min(self.cheapestStep(cost, 0), self.cheapestStep(cost, 1))