class Solution(object):
    def runningSum(self, nums):
        result = [0] * len(nums)
        for i in range(len(nums)):
            for j in range(i+1):
                result[i] += nums[j]
        return result
        