class Solution(object):
    def longestCommonPrefix(self, strs):
        print(min(strs))
        lensorted = sorted(strs, key=len)
        standard = lensorted[0]
        count = 0
        while count<len(standard):
            for str in lensorted[1:]:
                if standard[:count+1] != str[:count+1]:
                    return standard[:count] 
            count+=1
        return standard
                    