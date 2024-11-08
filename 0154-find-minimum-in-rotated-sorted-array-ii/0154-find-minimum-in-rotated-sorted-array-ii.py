class Solution(object):
    def findMin(self, nums):
        start, end = 0, len(nums)-1
        while start < end:
            mid = start + (end-start)//2
            if nums[start] == nums[mid] and nums[mid] == nums[end]:
                start += 1
                end -= 1
            elif nums[start] <= nums[mid] and nums[mid] <= nums[end]:
                break
            elif nums[start] <= nums[mid] and nums[mid] >= nums[end]:
                start = mid+1
            elif nums[start] >= nums[mid] and nums[mid] <= nums[end]:
                end = mid
            
        return nums[start]