class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        start, end = 0, len(numbers)-1
        mid = len(numbers) // 2
        
        while numbers[start]+numbers[end] != target:
            if (target-numbers[start]) in numbers:
                if numbers[mid] > target-numbers[start]:
                    end = mid-1
                    mid = (start+end) // 2
            elif (target-numbers[end]) in numbers:
                if numbers[mid] < target-numbers[end]:
                    start = mid+1
                    mid = (start+end) // 2
    
        return [start+1, end+1]