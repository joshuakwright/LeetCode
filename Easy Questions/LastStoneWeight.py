# Much faster solution in nlogn time using heap

class Solution(object):
    def lastStoneWeight(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """
        for i in range(len(stones)):
            stones[i] *= -1
            
        heapq.heapify(stones)
        
        while len(stones) > 1:
            stone1 = heapq.heappop(stones)
            stone2 = heapq.heappop(stones)
            
            if stone1 != stone2:
                heapq.heappush(stones, stone1 - stone2)
            
        return -heapq.heappop(stones) if stones else 0


# Intitial super slow n^2 solution:

class Solution(object):
    def remove_largest(self, stones):
        indexOfLargest = stones.index(max(stones))
        stones[indexOfLargest], stones[-1] = stones[-1], stones[indexOfLargest]
        return stones.pop()
    
    def lastStoneWeight(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """
        while len(stones) > 1:
            stone1 = self.remove_largest(stones)
            stone2 = self.remove_largest(stones)
            if stone1 != stone2:
                stones.append(stone1 - stone2)
            
        return stones[0] if stones else 0