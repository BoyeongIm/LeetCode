class Solution(object):   
    def searchInsert(self, nums, target):
        if target > nums[-1]:
            return len(nums)
        elif target < nums[0]:
            return 0
        elif target == nums[0]:
            return 0

        start, end = 0, len(nums)-1 

        while start<end:
            mid = (start+end)//2
            if nums[mid] < target:
                start = mid+1
            else:
                end = mid-1
        if nums[start]>=target:
            return start
        else nums[start]<target:
            return start+1