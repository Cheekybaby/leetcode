func maxProfit(prices []int) int {
    sell := prices[len(prices)-1]
    total_profit := 0
    for i := len(prices)-2; i >= 0; i-- {
        if prices[i] < sell {
            // in this case we sell and make the current day as next sell
            profit := sell - prices[i]
            total_profit += profit
            sell = prices[i]
        } else {
            // we make the current as the new sell
            sell = prices[i]
        }
    }

    return total_profit
}