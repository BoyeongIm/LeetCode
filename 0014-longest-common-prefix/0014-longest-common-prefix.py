class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        lensorted = sorted(strs, key=len)
        standard = lensorted[0]
        count = 0
        while count<len(standard):
            for str in strs:
                if standard[0:count+1] != str[0:count+1]:
                    return standard[0:count] 
            count+=1
        return standard
                    