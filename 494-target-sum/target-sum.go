const OFFSET = 1000
const n = 22
func solve(nums []int, target int, sum int, idx int, dp [][]int) int {
	if idx == len(nums) {
		if target == sum {
			return 1
		}
		return 0
	}

	if dp[idx][OFFSET+sum] != -1 {
		return dp[idx][OFFSET+sum]
	}

	add := solve(nums, target, sum+nums[idx], idx+1, dp)
    sub := solve(nums, target, sum-nums[idx], idx+1, dp)

	dp[idx][OFFSET+sum] = add + sub
    return dp[idx][OFFSET+sum]
}

func findTargetSumWays(nums []int, target int) int {
	dp := initDP()
	return solve(nums, target, 0, 0, dp)
}

func initDP() (dp [][]int) {
	dp = make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, 4*OFFSET)
		for j := range dp[i] {
			dp[i][j] = -1
		}
	}
	return dp
}