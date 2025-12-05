func rob(nums []int) int {
    dp := make([]int, len(nums)+1)
    dp[1] = nums[0]

    for i := 1; i < len(nums); i++ {
        rob := nums[i] + dp[i-1]
        not_rob := dp[i]
        dp[i+1] = max(rob, not_rob)
    }

    return dp[len(nums)]
}