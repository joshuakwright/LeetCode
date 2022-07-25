//My intitial pretty fast solution

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