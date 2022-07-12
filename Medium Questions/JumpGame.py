//Fast smart solution running in O(n) time

class Solution(object):    
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        lastPos = len(nums) - 1
        for i in range(len(nums) - 1, -1, -1):
            if i + nums[i] >= lastPos:
                lastPos = i
                
        return lastPos == 0

// Faster but still O(n^2) except this time using Bottom-up dynamic programming and getting rid of recursion so no stack frame is needed

class Use():
    UNKNOWN = 0
    GOOD = 1

class Solution(object):    
    memo = []
    
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        self.memo = [Use.UNKNOWN] * len(nums)
        self.memo[len(nums) - 1] = Use.GOOD
        
        for i in range(len(nums) - 2, -1, -1):
            furthestJump = min(i + nums[i], len(nums) - 1)
            for j in range(i + 1, furthestJump + 1):
                if self.memo[j] == Use.GOOD:
                    self.memo[i] = Use.GOOD
                    break
        
        return self.memo[0] == Use.GOOD

// Faster but still slow solution using Top-Down dynamic programming running in O(n^2)

class Use():
    UNKNOWN = 0
    GOOD = 1
    BAD = 2

class Solution(object):    
    memo = []
    
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        self.memo = [Use.UNKNOWN] * len(nums)
        self.memo[len(nums) - 1] = Use.GOOD
        
        return self.canJumpFromPosition(0, nums)
    
    def canJumpFromPosition(self, position, nums):
        if self.memo[position] != Use.UNKNOWN:
            return 1 if self.memo[position] == Use.GOOD else 0
                
        furthestJump = min(position + nums[position], len(nums) - 1)
        for nextPosition in range(furthestJump, position, -1):
            if self.canJumpFromPosition(nextPosition, nums): 
                self.memo[position] = Use.GOOD
                return 1

        self.memo[position] = Use.BAD
        return 0

//Initial super slow recursive solution running in O(2^n) time

class Solution(object):    
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        return self.canJumpFromPosition(0, nums)
    
    def canJumpFromPosition(self, position, nums):
        if position == len(nums) - 1: return 1
        
        furthestJump = min(position + nums[position], len(nums) - 1)
        for nextPosition in range(furthestJump, position, -1):
            if self.canJumpFromPosition(nextPosition, nums): return 1
        
        return 0