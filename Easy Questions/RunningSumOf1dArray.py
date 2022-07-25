//Initial fast solution

class Solution(object):
    def runningSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        length = len(nums)
        if length == 1:
            return nums
            
        for i in range(1, length):
            nums[i] = nums[i] + nums[i - 1]
            
        return nums