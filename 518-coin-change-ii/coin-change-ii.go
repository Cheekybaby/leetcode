func solve(coins []int, amount int, idx int, dp [][]int) int {
    if idx < 0 || amount < 0 { return 0 }
    if amount == 0 { return 1 }

    if dp[idx][amount] != -1 {
        return dp[idx][amount]
    }

    take, not_take := 0, 0
    if amount >= coins[idx] {
        take = solve(coins, amount - coins[idx], idx, dp)
    }
    not_take = solve(coins, amount, idx-1, dp)

    dp[idx][amount] = take + not_take
    return dp[idx][amount]
}

func change(amount int, coins []int) int {
    n := len(coins)
    dp := make([][]int, n)
    for i := range dp {
        dp[i] = make([]int, amount + 1)
        for j := range dp[i] {
            dp[i][j] = -1
        }
    }

    ways := solve(coins, amount, n-1, dp)

    return ways
}