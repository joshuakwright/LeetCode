# Slightly optimized second version:

class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        length = 0
        charCount = {}
        for c in s:
            if c in charCount.keys():
                charCount[c] += 1
                if charCount[c] % 2 == 0:
                    length += 2
            else:
                charCount[c] = 1

                
        if length < len(s):
            length += 1
            
        return length

# My initial ok solution:

class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        length = 0
        charCount = {}
        oddNum = 0
        for c in s:
            if c in charCount.keys():
                charCount[c] += 1
                if charCount[c] % 2 == 0:
                    length += 2
                    oddNum -= 1
                else:
                    oddNum += 1
            else:
                charCount[c] = 1
                oddNum += 1
                
        if oddNum:
            length += 1
            
        return length