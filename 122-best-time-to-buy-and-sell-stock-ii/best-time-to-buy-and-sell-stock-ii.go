func maxProfit(prices []int) int {
    max_profit := 0
    sell := math.MinInt

    n := len(prices)

    for i := n-1; i >= 0; i-- {
        if prices[i] > sell {
            sell = prices[i]
            continue
        }

        profit := sell - prices[i]
        max_profit += profit
        
        sell = prices[i]
    }

    return max_profit
}