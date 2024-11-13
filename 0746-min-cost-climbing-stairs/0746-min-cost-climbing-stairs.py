class Solution(object):
    def minCostClimbingStairs(self, cost):
        n = len(cost)
        stairs = [0 for i in range(n)]
        stairs[0] = cost[0]
        stairs[1] = min(cost[1], cost[0]+cost[1])

        for i in range(2, n):
            stairs[i] = min(stairs[i-1]+cost[i], stairs[i-2]+cost[i])

        return min(stairs[-1], stairs[-2])