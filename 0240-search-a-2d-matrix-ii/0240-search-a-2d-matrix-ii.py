class Solution(object):
    def binarySearch(self, arr, left, right, target):
        while left <= right:
            mid = (left + right)/2
            if arr[mid] == target:
                return mid
            if arr[mid] < target:
                left = mid+1
            else:
                right = mid-1
        return -1

    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if len(matrix) == 1:
            if target in matrix[0]:
                return True
            else:
                return False
        
        idx = 0
        while idx < len(matrix):
            result = self.binarySearch(matrix[idx], 0, len(matrix[idx])-1, target)
            if result != -1:
                return True
            idx += 1
        return False
        