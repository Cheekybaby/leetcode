const OFFSET = 3001
const n = 32
func solve(stones []int, sum, idx int, dp [][]int) int {
    if idx == len(stones) {
        if sum < 0 {
            return 4000
        }
        return sum
    }

    if dp[idx][sum+OFFSET] != -1 {
        return dp[idx][sum+OFFSET]
    }

    add := solve(stones, sum + stones[idx], idx+1, dp)
    sub := solve(stones, sum - stones[idx], idx+1, dp)

    dp[idx][sum+OFFSET] = min(add, sub)
    
    return dp[idx][sum+OFFSET]
}

func lastStoneWeightII(stones []int) int {
    dp := initDP()
    return solve(stones, 0, 0, dp)
}

func initDP() (dp [][]int) {
    dp = make([][]int, n)
    for i := range dp {
        dp[i] = make([]int, 6004)
        for j := range dp[i] {
            dp[i][j] = -1
        }
    }
    return dp
}