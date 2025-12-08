const MAX = math.MaxInt

func solve(coins []int, amount, idx int, dp [][]int) int {
    if amount == 0 {
        return 0
    }
    if idx >= len(coins) || amount < 0 {
        return MAX
    }

    if dp[idx][amount] != -1 {
        return dp[idx][amount]
    }

    take := MAX
    if coins[idx] <= amount {
        val := solve(coins, amount - coins[idx], idx, dp)
        if val != MAX {
            take = 1 + val
        }
    }
    not_take := solve(coins, amount, idx+1, dp)

    dp[idx][amount] = min(take, not_take)
    return dp[idx][amount]
}

func coinChange(coins []int, amount int) int {
    dp := initDP(len(coins), amount)
    min_coins := solve(coins, amount, 0, dp)

    if min_coins == MAX {
        return -1
    }

    return min_coins
}

func initDP(n, m int) (dp [][]int) {
    dp = make([][]int, n+1)
    for i := range dp {
        dp[i] = make([]int, m+1)
        for j := range dp[i] {
            dp[i][j] = -1
        }
    }

    return dp
}