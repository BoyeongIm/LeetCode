class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if len(s) == 1:
            return True;

        s = s.lower()
        new_str = ""
        for i in range(len(s)):
            if (s[i]>='0' and s[i]<='9') or (s[i]>='a' and s[i]<='z'):
                new_str += s[i]
        for j in range(len(new_str)//2):
            if new_str[j] != new_str[len(new_str)-1-j]:
                return False

        return True