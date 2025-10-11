func deleteAndEarn(nums []int) int {
    max_ele := nums[0]
    for i := range nums {
        max_ele = max(max_ele, nums[i])
    }

    dp := make([]int, max_ele+5)
    for _, val := range nums {
        dp[val]+=val
    }

    for i := max_ele; i >= 0; i-- {
        dp[i] = max(dp[i] + dp[i+2], dp[i+1])
    }

    return dp[0]
}