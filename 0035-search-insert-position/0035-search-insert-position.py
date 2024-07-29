class Solution(object):   
    def searchInsert(self, nums, target):
        start, end = 0, len(nums)-1 

        while start<end:
            mid = (start+end)//2
            if nums[mid] < target:
                start = mid+1
            else:
                end = mid-1
        if nums[start]>=target:
            return start
        elif nums[start]<target:
            return start+1