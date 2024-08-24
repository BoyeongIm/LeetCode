class Solution(object):
    def canThreePartsEqualSum(self, arr):
        eachsum = sum(arr)/3
        s = 0
        idx = 0 
        count = 0
        while idx < len(arr):
            s += arr[idx]
            idx += 1
            if s == eachsum and count<3:
                s = 0
                count += 1
        if count == 3:
            return True
        else:
            return False