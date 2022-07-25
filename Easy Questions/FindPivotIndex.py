//Initial solution

class Solution(object):
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        S = sum(nums)
        leftSum=0
        for i, x in enumerate(nums):
            if S - leftSum - x == leftSum:
                return i
            leftSum += x
            
        return -1

//Alternate equally as fast

class Solution(object):
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        lSum = 0
        rSum = sum(nums)
        for i, x in enumerate(nums):
            rSum -= x
            if lSum == rSum:
                return i
            lSum += x
            
        return -1