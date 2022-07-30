# Much faster one pass solution:

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        
        minPrice = prices[0]
        maxProfit = 0
        for i in range(1, len(prices)):
            if prices[i] - minPrice > maxProfit:
                maxProfit = prices[i] - minPrice
            if prices[i] < minPrice:
                minPrice = prices[i]
            
        return maxProfit


# My initial super slow solution:

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        
        max = 0
        for i in range(len(prices) - 1, -1, -1):
            for j in range(i - 1, -1, -1):
                if prices[i] - prices[j] > max:
                    max = prices[i] - prices[j]
        
        return max