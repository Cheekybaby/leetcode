const OFFSET = 100100
const n = 22
func solve(nums []int, target int, idx int, dp [][]int) int {
	if idx == len(nums) {
		if target == 0 {
			return 1
		}
		return 0
	}

	if dp[idx][OFFSET+target] != -1 {
		return dp[idx][OFFSET+target]
	}

	dp[idx][OFFSET+target] = solve(nums, target+nums[idx], idx+1, dp) + solve(nums, target-nums[idx], idx+1, dp)

	return dp[idx][OFFSET+target]
}

func findTargetSumWays(nums []int, target int) int {
	dp := initDP()
	return solve(nums, target, 0, dp)
}

func initDP() (dp [][]int) {
	dp = make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, 2*OFFSET)
		for j := range dp[i] {
			dp[i][j] = -1
		}
	}
	return dp
}