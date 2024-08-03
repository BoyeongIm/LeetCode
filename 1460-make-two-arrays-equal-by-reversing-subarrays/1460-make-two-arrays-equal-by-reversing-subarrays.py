class Solution(object):        
    def canBeEqual(self, target, arr):
        """
        :type target: List[int]
        :type arr: List[int]
        :rtype: bool
        """
        for t in target:
            if t not in arr:
                return False
        return True
        
