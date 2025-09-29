var dp = make([][]int, 22)
const OFFSET = 1001
func solve(nums []int, target, sum, idx int) int {
    if idx >= len(nums) {
        if target == sum {
            return 1
        }
        return 0
    }

    if dp[idx][OFFSET+sum] != -1 {
        return dp[idx][OFFSET+sum]
    }

    add := solve(nums, target, sum + nums[idx], idx+1)
    sub := solve(nums, target, sum - nums[idx], idx+1)

    dp[idx][OFFSET+sum] = add + sub
    return dp[idx][OFFSET+sum]
}

func findTargetSumWays(nums []int, target int) int {
    initDP()
    return solve(nums, target, 0, 0)
}

func initDP() {
    for i := range dp {
        dp[i] = make([]int, 2200)
        for j := range dp[i] {
            dp[i][j] = -1
        }
    }
}