class Solution(object):
    def findPermutationDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        diff = 0
        for i in range(len(s)):
            j = t.index(s[i])
            diff += abs(i-j)
        return diff