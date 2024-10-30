class Solution(object):
    def maxProfit(self, prices):
        max_profit = 0
        min_price = prices[0]
        for p in prices[1:]:
            if p-min_price > max_profit:
                max_profit = p - min_price
            if p < min_price:
                min_price = p

        return max_profit