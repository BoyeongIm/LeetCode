class Solution(object):
    def findMin(self, nums):
        start, end = 0, len(nums)-1
        while start < end:
            mid = start + (end-start)//2
            if nums[start] < nums[mid] and nums[end] >= nums[mid]:
                break
            elif nums[start] <= nums[mid] and nums[mid] > nums[end]:
                start = mid+1
            elif nums[start] >= nums[mid] and nums[mid] < nums[end]:
                end = mid
            elif nums[start] < nums[mid] and nums[mid] >= nums[end]:
                start = mid
            elif nums[start] > nums[mid] and nums[mid] <= nums[end]:
                end = mid
            elif nums[start] == nums[mid] and nums[mid] == nums[end]:
                start = start+1
                end = end-1
            else:
                break
        return nums[start]