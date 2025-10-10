func solve(nums []int, idx int, dp []int) int {
    if idx >= len(nums) {
        return 0
    }

    if dp[idx] != -1 {
        return dp[idx]
    }

    rob := nums[idx] + solve(nums, idx+2, dp)
    not_rob := solve(nums, idx+1, dp)

    dp[idx] = max(rob, not_rob)
    return dp[idx]
}

func rob(nums []int) int {
    dp := initDP(len(nums))
    return solve(nums, 0, dp)
}
func initDP(n int) (dp []int) {
    dp = make([]int, n+1)
    for i := range dp {
        dp[i] = -1
    }
    return dp
}