class Solution(object):
    def merge(self, nums1, m, nums2, n):
        if m==0:
            nums1[:n] = nums2[:n]
        elif n==0:
            nums1 = nums1[:m]
        else:
            nums1[m:m+n] = nums2[:n]
            nums1.sort()