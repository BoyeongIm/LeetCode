class Solution(object):
    def longestCommonPrefix(self, strs):
        lensorted = sorted(strs, key=len)
        standard = lensorted[0]
        count = 0
        while count<len(standard):
            for str in lensorted[1:]:
                if standard[0:count+1] != str[0:count+1]:
                    return standard[0:count] 
            count+=1
        return standard
                    