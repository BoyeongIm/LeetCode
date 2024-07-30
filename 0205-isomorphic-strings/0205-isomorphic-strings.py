class Solution(object):
    def isIsomorphic(self, s, t):
        if len(s)==1 and len(t)==1:
            return True
        isomdict={}
        for i in range(len(s)):
            if s[i] not in isomdict.keys():
                if t[i] not in isomdict.values():
                    isomdict[s[i]] = t[i]
                else:
                    return False
            elif s[i] in isomdict.keys():
                if isomdict[s[i]] != t[i]:
                    return False

        return True
                