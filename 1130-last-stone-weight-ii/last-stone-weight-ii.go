const OFFSET = 3001

func solve(stones []int, idx int, sum int, total int, dp [][]int) int {
    if idx >= len(stones) {
        return abs(total - 2 * sum)
    }

    if dp[idx][sum + OFFSET] != -1 {
        return dp[idx][sum + OFFSET]
    }

    take := solve(stones, idx+1, sum + stones[idx], total, dp)
    not_take := solve(stones, idx+1, sum, total, dp)

    dp[idx][sum + OFFSET] = min(take, not_take)

    return dp[idx][sum + OFFSET]
}
func lastStoneWeightII(stones []int) int {
    n := len(stones)
    dp := make([][]int, n)
    for i := range dp {
        dp[i] = make([]int, 2 * OFFSET)
        for j := range dp[i] {
            dp[i][j] = -1
        }
    }

    total := 0
    for _, num := range stones {
        total += num
    }
    return solve(stones, 0, 0, total, dp)
}
func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}