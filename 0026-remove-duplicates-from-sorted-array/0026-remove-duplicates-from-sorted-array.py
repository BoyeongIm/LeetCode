class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 1
        
        idx = 0
        while idx < len(nums)-1:
            if nums[idx] == nums[idx+1]:
                nums.pop(idx)
            else:
                idx += 1
        return len(nums)