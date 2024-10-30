class Solution(object):
    def maxProfit(self, prices):
        min_price = 10001
        max_price = -1
        max_profit = 0

        i,j = 0, len(prices)-1
        while i <= j:        
            if prices[i] < min_price:
                min_price = prices[i]
            if prices[j] > max_price:
                max_price = prices[j]
            if max_profit < max_price-min_price:
                max_profit = max_price-min_price
            i += 1 
            j -= 1

        return max_profit