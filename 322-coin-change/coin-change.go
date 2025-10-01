var dp = make([][]int, 13)

func solve(nums []int, idx, target int) int {
    if target == 0 {
        return 0
    }
    if idx >= len(nums) || target < 0 {
        return math.MaxInt
    }

    if dp[idx][target] != -1 {
        return dp[idx][target]
    }

    take := math.MaxInt
    if target >= nums[idx] {
        val := solve(nums, idx, target - nums[idx])
        if val != math.MaxInt {
            take = 1 + val
        }
    }
    not_take := solve(nums, idx+1, target)

    dp[idx][target] = min(take, not_take)
    return dp[idx][target]
}

func coinChange(coins []int, amount int) int {
    initDP()

    ans := solve(coins, 0, amount)
    
    if ans == math.MaxInt {
        return -1
    }
    return ans
}

func initDP() {
    for i := range dp {
        dp[i] = make([]int, 10004)
        for j := range dp[i] {
            dp[i][j] = -1
        }
    }
}