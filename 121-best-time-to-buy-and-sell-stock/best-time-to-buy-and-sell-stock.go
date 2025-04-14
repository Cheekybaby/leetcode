func maxProfit(prices []int) int {
    buy := prices[0]
    profit := 0
    for i:=1; i<len(prices); i++ {
        if prices[i] < buy {
            buy = prices[i]
        }

        profit = max(profit, prices[i] - buy)
    }

    return profit
}