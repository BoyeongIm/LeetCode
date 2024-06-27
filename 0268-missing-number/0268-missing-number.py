class Solution(object):
    def missingNumber(self, nums):
        # my solution
        nums.sort()
        i=0
        while nums[i] == i and i<len(nums)-1:
            i += 1
        if nums[i] == i:
            return len(nums)
        else: 
            return i
            
        '''
        # other solution 1 : using the sum
        target_sum = len(nums)*(len(nums)+1) / 2
        my_sum = sum(nums)

        return target_sum - my_sum

        # other solution 2 : three cases
        nums.sort()
        if nums[0] != 0:
            return 0
        if nums[-1] != len(nums):
            return len(nums)
        for i in range(1, len(nums)):
            if nums[i] != i:
                return i
        return 0 
        '''