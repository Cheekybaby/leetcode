func solve(nums []int, idx int, dp []int) int {
    if idx >= len(nums) {
        return 0
    }

    if dp[idx] != -1 {
        return dp[idx]
    }

    rob := nums[idx] +  solve(nums, idx+2, dp)
    not_rob := solve(nums, idx+1, dp)

    dp[idx] = max(rob, not_rob)

    return dp[idx]
}

func rob(nums []int) int {
    dp := make([]int, len(nums))
    for i := range dp {
        dp[i] = -1
    }

    max_rob := solve(nums, 0, dp)

    return max_rob
}