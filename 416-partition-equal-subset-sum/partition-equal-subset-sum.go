var dp = make([][]int, 202)
func solve(nums []int, target, sum, idx int) bool {
    if idx >= len(nums) {
        return (sum == target)
    }
    if target == sum {
        return true
    }

    if dp[idx][sum] != -1 {
        return (dp[idx][sum] == 1)
    }

    take := solve(nums, target, sum + nums[idx], idx+1)
    not_take := solve(nums, target, sum, idx+1)

    if (take || not_take) {
        dp[idx][sum] = 1
    } else {
        dp[idx][sum] = 0
    }

    return (dp[idx][sum] == 1)
}
func canPartition(nums []int) bool {
    sum := 0
    for _, val := range nums {
        sum += val
    }
    
    if (sum % 2) == 1 {
        return false
    }

    target := sum/2
    initDP()
    return solve(nums, target, 0, 0)
}
func initDP() {
    for i := range dp {
        dp[i] = make([]int, 20001)
        for j := range dp[i] {
            dp[i][j] = -1
        }
    }
}