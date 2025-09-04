func maxProfit(prices []int, strategy []int, k int) int64 {
    n := len(prices)
    winSize := k/2

    pnl := make([]int64, n)
    var base int64
    for i := range prices {
        pnl[i] = int64(prices[i]) * int64(strategy[i])
        base += pnl[i]
    }

    win_original := int64(0)
    for i:=0; i<k; i++ {
        win_original += pnl[i]
    }
    win_change := int64(0)
    for i:=winSize; i<k; i++ {
        win_change += int64(prices[i])
    }

    maxChange := win_change - win_original

    for i := 1; i <= n-k; i++ {
        win_original += (pnl[i+k-1] - pnl[i-1])
        win_change += int64(prices[i+k-1] - prices[i-1+winSize])

        maxChange = max(maxChange, win_change - win_original)
    }

    return base + max(0, maxChange)
}