class Solution(object):
    def percentageLetter(self, s, letter):
        if letter not in s:
            return 0
        n = len(s)
        count = 0
        for c in s:
            if c == letter:
                count += 1
        
        return 100*count/n