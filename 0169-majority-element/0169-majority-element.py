class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        freqdict = {}
        for i in range(n):
            if nums[i] not in freqdict:
                freqdict[nums[i]] = 1
            else:
                freqdict[nums[i]] += 1
            if freqdict[nums[i]] > n/2:
                return nums[i]
        