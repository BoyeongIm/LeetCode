class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        max_profit = 0
        left = 0
        right = 1

        while right < len(prices):
            current_profit = prices[right]-prices[left]
            if prices[left] < prices[right] :
                max_profit = max(max_profit, current_profit)
            else:
                left = right
            
            right+=1

        return max_profit