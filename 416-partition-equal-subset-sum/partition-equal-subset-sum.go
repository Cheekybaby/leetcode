func solve(nums []int, idx, sum, target int, dp [][]int) bool {
    if idx >= len(nums) {
        if sum == target {
            return true
        }
        return false
    }

    if sum > target {
        return false
    }

    if dp[idx][sum] != -1 {
        return dp[idx][sum] == 1
    }

    not_take := solve(nums, idx+1, sum, target, dp)
    take := false
    if sum + nums[idx] <= target {
        take = solve(nums, idx+1, sum + nums[idx], target, dp)
    }

    dp[idx][sum] = 0
    if take || not_take {
        dp[idx][sum] = 1
    }
    return (dp[idx][sum] == 1)
}

func canPartition(nums []int) bool {
    n := len(nums)
    total := 0
    for _, num := range nums {
        total += num
    }
    if (total & 1) == 1 {
        return false
    }
    dp := make([][]int, n)
    for i := range dp {
        dp[i] = make([]int, total/2 + 1)
        for j := range dp[i] {
            dp[i][j] = -1
        }
    }
    return solve(nums, 0, 0, total/2, dp)
}