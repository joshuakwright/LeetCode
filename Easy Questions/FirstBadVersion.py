# Initial Fast version

# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        left, right = 1, n
        while left < right:
            if left == right - 1:
                break
            
            pivot = (left + right) / 2
            gb = isBadVersion(pivot)
            if gb is False:
                left = pivot
            else:
                right = pivot
                
        return right if isBadVersion(left) is False else left

# A more condensed version:

# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        left, right = 1, n
        while left < right:
            pivot = (left + right) / 2
            if isBadVersion(pivot) is False:
                left = pivot + 1
            else:
                right = pivot
                
        return left