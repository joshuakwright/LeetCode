# Much faster elegant solution:

class Solution(object):    
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """     
        return len(set(s)) == len(set(t)) == len(set(zip(s, t)))

# Still slightly faster solution using a transform:

class Solution(object):
    def transform(self, string):
        indexMap = {}
        transString = []
        
        for i, c in enumerate(string):
            if c not in indexMap:
                indexMap[c] = i
            transString.append(str(indexMap[c]))
 
        return " ".join(transString)
    
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """     
        return self.transform(s) == self.transform(t)

# Slightly faster second solution:

class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        sCharMap = {}
        tCharMap = {}
        for i in range(len(s)):
            if sCharMap.has_key(s[i]) is False and tCharMap.has_key(t[i]) is False:
                sCharMap[s[i]] = t[i]
                tCharMap[t[i]] = s[i]
            elif sCharMap.get(s[i]) != t[i] or tCharMap.get(t[i]) != s[i]:
                return False
                
        return True

# My original slow solution:

class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        sCharMap = {s[0] : t[0]}
        tCharMap = {t[0] : s[0]}
        for i in range(1, len(s)):
            if sCharMap.has_key(s[i]) != tCharMap.has_key(t[i]):
                return False
            elif sCharMap.has_key(s[i]) and sCharMap[s[i]] != t[i]:
                return False
            elif tCharMap.has_key(t[i]) and tCharMap[t[i]] != s[i]:
                return False
            else:
                sCharMap[s[i]] = t[i]
                tCharMap[t[i]] = s[i]
                
        return True
        