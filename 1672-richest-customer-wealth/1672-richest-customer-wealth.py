class Solution(object):
    def maximumWealth(self, accounts):
        max = 0
        for i in range(len(accounts)):
            result = sum(accounts[i])
            if (result > max):
                max = result
        return max
        