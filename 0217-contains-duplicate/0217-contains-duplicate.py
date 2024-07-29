class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        nset = set(nums)
        if len(nums) == len(nset):
            return False
        else:
            return True