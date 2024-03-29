# Same concept but constant space 

class Solution(object):
    def fib(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0: return 0
        if n == 1: return 1
        
        prev1 = 0
        prev2 = 1
        for i in range(2, n + 1):
            fib = prev1 + prev2
            prev1 = prev2
            prev2 = fib
        
        return fib

# My intitial pretty fast solution

class Solution(object):
    def fib(self, n):
        """
        :type n: int
        :rtype: int
        """
        Fn = [0, 1]
        for i in range(2, n + 1):
            Fn.append(Fn[i - 1] + Fn[i - 2])
        
        return Fn[n]