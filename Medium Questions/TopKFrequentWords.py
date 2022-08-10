# Solution using heap so time is now nlogk:

class Solution(object):
    def topKFrequent(self, words, k):
        """
        :type words: List[str]
        :type k: int
        :rtype: List[str]
        """
        count = Counter(words)
        return heapq.nsmallest(k, count, key= lambda word: (-count[word], word))
        


# Initial simple solution in nlogn time:

class Solution(object):
    def topKFrequent(self, words, k):
        """
        :type words: List[str]
        :type k: int
        :rtype: List[str]
        """
        count = Counter(words)
        return sorted(count, key = lambda x: (-count[x], x))[:k]
        
        
        