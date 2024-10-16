class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)==1:
            return nums[0]
        
        s = 0
        m = -10001
        for i in range(len(nums)):
            s += nums[i]
            if s >= m:
                m = s
            if s < 0:
                s = 0
        return m