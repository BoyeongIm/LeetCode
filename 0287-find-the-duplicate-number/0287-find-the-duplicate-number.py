class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #nums.sort()
        start, end = 0, len(nums)-1
        while start < end:
            if nums[start] == nums[end]:
                break
            elif nums[start] in nums[start+1:]:
                break
            elif nums[end] in nums[:end]:
                start = end
                break
            else:
                start+=1

        return nums[start]