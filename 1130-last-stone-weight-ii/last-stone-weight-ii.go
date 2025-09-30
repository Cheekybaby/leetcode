var dp = make([][]int, 32)
func solve(nums []int, idx, sum, total int) int {
    if idx >= len(nums) {
        return abs(total - 2 * sum)
    }

    if dp[idx][sum] != -1 {
        return dp[idx][sum]
    }

    take := solve(nums, idx+1, sum + nums[idx], total)
    not_take := solve(nums, idx+1, sum, total)

    dp[idx][sum] = min(take, not_take)
    
    return dp[idx][sum]
}
func lastStoneWeightII(stones []int) int {
    var total int
    for _, val := range stones {
        total += val
    }
    initDP()
    return solve(stones, 0, 0, total)
}

func initDP() {
    for i := range dp {
        dp[i] = make([]int, 3001)
        for j := range dp[i] {
            dp[i][j] = -1
        }
    }
}
func abs(x int) int {
    if x < 0 {
        return -1 * x
    }
    return x
}