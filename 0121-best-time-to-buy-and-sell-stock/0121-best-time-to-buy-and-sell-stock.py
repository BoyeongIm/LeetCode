class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices)==1:
            return 0
            
        max_profit = 0
        min_price = 10001
        for i in range(len(prices)-1):
            if prices[i] < min_price:
                min_price = prices[i]
                min_idx = i

        for j in range(min_idx+1, len(prices)):
            if prices[j]-min_price > max_profit:
                max_profit = prices[j]-min_price
        
        return max_profit