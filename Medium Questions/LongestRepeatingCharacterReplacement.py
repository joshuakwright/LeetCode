# Initial optimal solution:

class Solution(object):
    def characterReplacement(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        maxSubString = result = 0
        frequency = Counter()
        for i in range(len(s)):
            frequency[s[i]] += 1
            maxSubString = max(maxSubString, frequency[s[i]])
            if result - maxSubString < k:
                result += 1
            else:
                frequency[s[i - result]] -= 1
            
        return result