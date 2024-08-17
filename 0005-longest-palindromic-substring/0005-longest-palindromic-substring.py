class Solution(object):
    def longestPalindrome(self, s):
        if s==s[::-1]:
            return s
        
        n = len(s)
        longest = ""
        for i in range(n-1):
            for j in range(i+1, n+1):
                ss = s[i:j]
                if ss==ss[::-1] and len(ss) > len(longest):
                    longest = ss
        
        return longest