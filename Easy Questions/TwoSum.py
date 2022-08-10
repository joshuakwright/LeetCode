# Fastest one pass solution:

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        comp = {}
        for i in range(len(nums)):
            if target - nums[i] in comp.keys():
                return [comp[target - nums[i]], i]
            comp[nums[i]] = i