# Initial fast solution:

class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        sLen = len(s)
        tLen = len(t)
        
        if sLen == 0:
            return True
        if tLen == 0 or sLen > tLen:
            return False
        
        sIndex = 0
        for c in t:
            if c == s[sIndex]:
                sIndex += 1
                if sIndex == sLen:
                    return True
            
        return False