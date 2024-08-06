class Solution(object):
    def merge(self, nums1, m, nums2, n):
        if m==0:
            nums1[:n] = nums2[:n]
        elif n==0:
            return
        else:
            nums1[m:m+n] = nums2[:n]
            for i in range(len(nums1)-1):
                for j in range(i+1, len(nums1)):
                    if nums1[i]>nums1[j]:
                        nums1[i], nums1[j] = nums1[j], nums1[i]