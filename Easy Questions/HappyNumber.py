# Constant space solution using Floyd's cycle detection algorithm

class Solution(object):
    def sumDigitSquares(self, n):
        total = 0
        while n != 0:
            temp = n % 10
            total += pow(temp, 2)
            n /= 10
        
        return total
    
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        tortoise = n
        hare = self.sumDigitSquares(n)
        while hare != 1 and tortoise != hare:
            tortoise = self.sumDigitSquares(tortoise)
            hare = self.sumDigitSquares(self.sumDigitSquares(hare))
            
        return hare == 1

# Initial fast solution with set:

class Solution(object):
    def sumDigitSquares(self, n):
        total = 0
        while n != 0:
            temp = n % 10
            total += pow(temp, 2)
            n /= 10
        
        return total
    
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        currSum = self.sumDigitSquares(n)
        if currSum == 1:
            return True
        
        mem = {n}
        while currSum not in mem:
            mem.add(currSum)
            currSum = self.sumDigitSquares(currSum)
            if currSum == 1:
                return True
            
        return False