func solve(costs [][]int, idx int, l_a, l_b int, dp [][]int) int {
    if idx >= len(costs) {
        return 0
    }

    if dp[idx][l_a] != -1 {
        return dp[idx][l_a]
    }

    var a, b int = math.MaxInt, math.MaxInt
    if l_a < len(costs)/2 {
        a = costs[idx][0] + solve(costs, idx+1, l_a + 1, l_b, dp)
    }
    if l_b < len(costs)/2 {
        b = costs[idx][1] + solve(costs, idx+1, l_a, l_b + 1, dp)
    }

    dp[idx][l_a] = min(a, b)

    return dp[idx][l_a]
}

func twoCitySchedCost(costs [][]int) int {
    dp := make([][]int, len(costs))
    for i := range dp {
        dp[i] = make([]int, len(costs)/2 + 1)
        for j := range dp[i] {
            dp[i][j] = -1
        }
    }
    
    min_cost := solve(costs, 0, 0, 0, dp)

    return min_cost
}