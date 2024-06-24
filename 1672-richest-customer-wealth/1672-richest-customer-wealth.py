class Solution(object):
    def maximumWealth(self, accounts):
        max = 0
        for i in range(len(accounts)):
            result = sum(accounts[i])
            if (result > max):
                max = result
        return max

////////////////////////////////
// another efficient solution //
class Solution(object):
    def maximumWealth(self, accounts):
        return max(sum(acc) for acc in accounts)
