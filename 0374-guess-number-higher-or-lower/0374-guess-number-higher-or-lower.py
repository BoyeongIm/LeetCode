# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num):

class Solution(object):
    def guessNumber(self, n):
        start, end = 1, n
        mid = (start+end)/2
        result = guess(mid)
        while result != 0:
            if result == -1:
                end = mid - 1
            elif result == 1:
                start = mid + 1
            mid = (start+end)/2
            result = guess(mid)
        
        return start
            