# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n):
        if isBadVersion(1):
            return 1
        start, end = 1, n
        while start<=end:
            mid = (start+end)//2
            if isBadVersion(mid):
                end = mid-1
            else:
                start = mid+1
        if start<=n and isBadVersion(start):
            return start