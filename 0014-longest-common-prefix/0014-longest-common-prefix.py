class Solution(object):
    # def longestCommonPrefix(self, strs):
    #     lensorted = sorted(strs, key=len)
    #     standard = lensorted[0]
    #     count = 0
    #     while count<len(standard):
    #         for str in lensorted[1:]:
    #             if standard[:count+1] != str[:count+1]:
    #                 return standard[:count] 
    #         count+=1
    #     return standard
    def longestCommonPrefix(self, strs):
        lens = []
        minlength = 9999
        minlength_w = ""
        count = 0
        for s in strs:
            lens.append(len(s))
            if minlength > len(s):
                minlength = len(s)
                minlength_w = s
        while len(minlength_w)>0:
            for s in strs:
                if s[:len(minlength_w)] != minlength_w:
                    break
                count +=1        
            if count == len(strs):
                return minlength_w
            minlength_w = minlength_w[:-1]
            count = 0
        return minlength_w
                        