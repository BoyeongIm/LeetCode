class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if len(s) == 1:
            return True;

        new_str = ""
        for i in range(len(s)):
            if (s[i]>='0' and s[i]<='9') or (s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z'):
                new_str += s[i].lower()
        
        if new_str != new_str[::-1]:  # new_str의 전체를 "거꾸로" 읽어라!
            return False

        return True

        """
        for j in range(len(new_str)//2):
            if new_str[j] != new_str[len(new_str)-1-j]:
                return False
        """