class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()

        i=0
        while nums[i] == i and i<len(nums)-1:
            i += 1
        if nums[i] == i:
            return len(nums)
        else: 
            return i