class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minPrice = prices[0]
        maxProfit = 0

        for i in range(1, len(prices)):
            if minPrice > prices[i]:
                minPrice = prices[i]
            currProfit = prices[i] - minPrice
            if currProfit > maxProfit:
                maxProfit = currProfit
        
        return maxProfit
        