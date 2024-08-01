class Solution(object):
    def longestCommonPrefix(self, strs):
        #lensorted = sorted(strs, key=len)
        #standard = lensorted[0]
        count = 0
        while count<len(strs[0]):
            for str in strs[1:]:
                if str[0][:count+1] != str[:count+1]:
                    return strs[0][:count] 
            count+=1
        return strs[0]
                    