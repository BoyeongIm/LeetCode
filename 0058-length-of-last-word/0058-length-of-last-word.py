class Solution(object):
    def lengthOfLastWord(self, s):
        if len(s) == 1:
            return 1

        reversed = s[::-1]
        idx = 0
        length = 0
        while reversed[idx] == " ":
            idx += 1
        for i in range(idx, len(reversed)):
            if reversed[i] == " ":
                break
            length += 1

        return length