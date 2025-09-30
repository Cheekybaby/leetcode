var dp = make([][]int, 32)
const OFFSET = 3001
func solve(nums []int, idx, sum int) int {
    if idx >= len(nums) {
        if sum < 0 {
            return 10000
        }
        return sum
    }

    if dp[idx][OFFSET+sum] != -1 {
        return dp[idx][OFFSET+sum]
    }

    add := solve(nums, idx+1, sum + nums[idx])
    sub := solve(nums, idx+1, sum - nums[idx])

    dp[idx][OFFSET+sum] = min(add, sub)
    
    return dp[idx][OFFSET+sum]
}
func lastStoneWeightII(stones []int) int {
    initDP()
    return solve(stones, 0, 0)
}

func initDP() {
    for i := range dp {
        dp[i] = make([]int, 6002)
        for j := range dp[i] {
            dp[i][j] = -1
        }
    }
}