class Solution(object):
    def twoSum(self, numbers, target):
        start, end = 0, len(numbers)-1    
        """
        이건 time limit 걸림
        while numbers[start]+numbers[end] != target:
            if target-numbers[start] in numbers:
                end -= 1
            elif target-numbers[end] in numbers:
                start += 1
        """    

        while start < end:
            if numbers[start] + numbers[end] == target:
                return [start+1, end+1]
            elif numbers[start] + numbers[end] > target:
                end -= 1
            elif numbers[start] + numbers[end] < target:
                start += 1