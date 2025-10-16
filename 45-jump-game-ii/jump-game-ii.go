func solve(nums []int, idx int, dp []int) int {
    if idx >= len(nums) {
        return math.MaxInt
    }
    if idx == len(nums)-1 {
        return 1
    }

    j := nums[idx]

    if j == 0 {
        return math.MaxInt
    }
    
    if dp[idx] != -1 {
        return dp[idx]
    }

    ans := len(nums)
    for i := idx+1; i <= idx + j; i++ {
        val := solve(nums, i, dp)
        if val != math.MaxInt {
            ans = min(1 + val, ans)
        }
    }

    dp[idx] = ans

    return dp[idx]
}

func jump(nums []int) int {
    dp := initDP(len(nums))
    return solve(nums, 0, dp) - 1
}
func initDP(n int) (dp []int) {
    dp = make([]int, n+1)
    for i := range dp {
        dp[i] = -1
    }
    return dp
}