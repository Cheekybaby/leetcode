func solve(nums []int, last, idx, OFFSET int, dp[][]int) int {
    if idx == len(nums) {
        return 0
    }

    if dp[idx][OFFSET + last] != -1 {
        return dp[idx][OFFSET + last]
    }

    take := 0

    if last < nums[idx] {
        curr := last
        last = nums[idx]
        take = 1 + solve(nums, last, idx+1, OFFSET, dp)
        last = curr
    }

    not_take := solve(nums, last, idx+1, OFFSET, dp)

    dp[idx][OFFSET + last] = max(take, not_take)

    return dp[idx][OFFSET + last]
}

func lengthOfLIS(nums []int) int {
    mini, maxi := math.MaxInt, math.MinInt
    
    for _, val := range nums {
        mini = min(mini, val)
        maxi = max(maxi, val)
    }

    size := max(abs(maxi), abs(mini))
    if size == 0 {
        size = 2
    }
    dp := initDP(len(nums), 2 * size)

    last := mini-1
    return solve(nums, last, 0, 2 * size, dp)
}
func initDP(n, m int) (dp [][]int) {
    dp = make([][]int, n+1)
    for i := range dp {
        dp[i] = make([]int, 2*m)
        for j := range dp[i] {
            dp[i][j] = -1
        }
    }
    return dp
}
func abs(x int) int {
    if x < 0 {
        return -1 * x
    }
    return x
}