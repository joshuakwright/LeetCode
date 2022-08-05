# Solution using a constant array size instead of hash map:

class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        sLen, pLen = len(s), len(p)
        if sLen < pLen:
            return []
        
        pCount, sCount = [0] * 26, [0] * 26
        for c in p:
            pCount[ord(c) - ord('a')] += 1
        
        output = []
        for i in range(sLen):
            sCount[ord(s[i]) - ord('a')] += 1
            
            if i >= pLen:
                sCount[ord(s[i - pLen]) - ord('a')] -= 1
            
            if pCount == sCount:
                output.append(i - pLen + 1)
                
        return output
        

# Initial solution with hashmap:

class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        sLen, pLen = len(s), len(p)
        if sLen < pLen:
            return []
        
        pCount = Counter(p)
        sCount = Counter()
        
        output = []
        for i in range(sLen):
            sCount[s[i]] += 1
            
            if i >= pLen:
                if sCount[s[i - pLen]] == 1:
                    del sCount[s[i - pLen]]
                else:
                    sCount[s[i - pLen]] -= 1
            
            if pCount == sCount:
                output.append(i - pLen + 1)
                
        return output
        