#My faster but still slow solution

class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        
        i, j = 0, len(height) - 1
        maxArea = 0;
        
        while i < j:
            maxArea = max(min(height[i], height[j]) * (j-i), maxArea)
            if (height[i] < height[j]): 
                i += 1
            else: 
                j -= 1
        
        return maxArea


# My slow solution

class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        
        maxArea = 0;
        length = len(height)
        for i in range(0, length):
            for j in range(i, length):
                maxArea = max(min(height[i], height[j]) * (j-i), maxArea)
        
        return maxArea