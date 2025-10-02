var dp = make([][]int, 302)
func solve(nums []int, amount, idx int) int {
    if idx >= len(nums) {
        if amount == 0 {
            return 1
        }
        return 0
    }

    if amount < 0 {
        return 0
    }
    if amount == 0 {
        return 1
    }

    if dp[idx][amount] != -1 {
        return dp[idx][amount]
    }

    take := 0
    if amount >= nums[idx] {
        take = solve(nums, amount - nums[idx], idx)
    }
    not_take := solve(nums, amount, idx + 1)

    dp[idx][amount] = (take + not_take)

    return dp[idx][amount]
}

func change(amount int, coins []int) int {
    initDP()
    
    ans := solve(coins, amount, 0)

    return ans
}

func initDP() {
    for i := range dp {
        dp[i] = make([]int, 5005)
        for j := range dp[i] {
            dp[i][j] = -1
        }
    }
}