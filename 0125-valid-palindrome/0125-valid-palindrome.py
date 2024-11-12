class Solution(object):
    def isPalindrome(self, s):
        s = s.lower()
        combined = ''
        for w in s:
            if  w >= 'a' and w <= 'z':
                combined += w
            elif w >= '0' and w <= '9':
                combined += w
                
        return combined == combined[::-1]