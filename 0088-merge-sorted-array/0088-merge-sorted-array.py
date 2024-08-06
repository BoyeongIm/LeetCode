class Solution(object):
    def merge(self, nums1, m, nums2, n):
        if m==0:
            nums1[:n] = nums2[:n]
        elif n==0:
            return
        else:
            i1, i2, j = m-1, n-1, m+n-1
            while i2>=0:
                if i1>=0 and nums1[i1]>nums2[i2]:
                    nums1[j] = nums1[i1]
                    i1-=1
                else:
                    nums1[j] = nums2[i2]
                    i2-=1
                j-=1
                