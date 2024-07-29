class Solution(object):
    def containsDuplicate(self, nums):
        nset = set()
        for n in nums:
            if n in nset:
                return True
            nset.add(n)
        
        return False