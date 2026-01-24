func solve(coins []int, idx, amount int, dp [][]int) int {
    if idx < 0 || amount < 0 { return math.MaxInt }
    if amount == 0 { return 0 }

    if dp[idx][amount] != -1 {
        return dp[idx][amount]
    }

    take, not_take := math.MaxInt, math.MaxInt
    if amount >= coins[idx] {
        temp := solve(coins, idx, amount - coins[idx], dp)
        if temp != math.MaxInt {
            take = 1 + temp
        }
    }
    not_take = solve(coins, idx-1, amount, dp)

    dp[idx][amount] = min(take, not_take)
    return dp[idx][amount]
}

func coinChange(coins []int, amount int) int {
    n := len(coins)
    dp := make([][]int, n)
    for i := range dp {
        dp[i] = make([]int, amount + 1)
        for j := range dp[i] {
            dp[i][j] = -1
        }
    }
    ans := solve(coins, len(coins)-1, amount, dp)
    if ans == math.MaxInt { return -1 }
    return ans
}