class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if needle not in haystack:
            return -1
        else:
            hl = len(haystack)
            nl = len(needle)
            for i in range(hl-nl+2):
                if haystack[i:i+nl] == needle:
                    return i