class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        dp = [[1],[1,1]]
        if rowIndex == 0:
            return dp[0]
        if rowIndex == 1:
            return dp[1]
        idx = 2
        while idx <= rowIndex:
            l = [1] * (idx+1)
            for i in range(1, idx):
                l[i] = dp[idx-1][i-1] + dp[idx-1][i]
            dp.append(l)
            idx+=1

        return dp[rowIndex]