class Solution(object):
    def removePalindromeSub(self, s):
        if s==s[::-1]:
            return 1
        if s[1:]==s[:0:-1]:
            return 2
        if s[:-1]==s[-2::-1]:
            return 2
        else:
            return 1