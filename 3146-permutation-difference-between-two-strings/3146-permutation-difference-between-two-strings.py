class Solution(object):
    def findPermutationDifference(self, s, t):
        sdict = dict()
        tdict = dict()
        diff = 0
        for i in range(len(s)):
            sdict[s[i]] = i
            tdict[t[i]] = i
        
        for k in sdict.keys():
            diff += abs(sdict[k]-tdict[k])
        
        return diff