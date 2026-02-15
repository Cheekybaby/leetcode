func maxProfit(prices []int) int {
    max_profit := 0
    sell := prices[len(prices)-1]
    for i := len(prices)-2; i >= 0; i-- {
        if prices[i] > sell {
            sell = prices[i]
        }
        profit := sell - prices[i]

        max_profit = max(max_profit, profit)
    }

    return max_profit
}