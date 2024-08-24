class Solution(object):
    def lengthOfLastWord(self, s):
        if len(s) == 1:
            return 1

        idx = len(s)-1
        length = 0

        while s[idx] == " ":
            idx -= 1
            
        for i in range(idx, -1, -1):
            if s[i] == " ":
                break
            length += 1

        return length