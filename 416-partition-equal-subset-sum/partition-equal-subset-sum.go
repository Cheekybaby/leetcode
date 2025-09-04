func solve(nums []int, sum, idx int, dp [][]int) bool {
    if sum == 0 {
        return true
    }
    if sum < 0 {
        return false
    }
    if idx == len(nums) {
        return false
    }
    if dp[idx][sum] != -1 {
        return dp[idx][sum] == 1
    }

    take := solve(nums, sum-nums[idx], idx+1, dp)
    not_take := solve(nums, sum, idx+1, dp)

    if take || not_take {
        dp[idx][sum] = 1
    } else {
        dp[idx][sum] = 0
    }

    return dp[idx][sum] == 1
}

func canPartition(nums []int) bool {
    sum := 0
    for i := range nums {
        sum += nums[i]
    }

    if sum & 1 == 1 {
        return false
    }

    sum /= 2
    dp := initDP(int(len(nums)), sum)
    // Now it's a subset sum problem
    return solve(nums, sum, 0, dp)
}

func initDP(n, m int) (matrix [][]int) {
    matrix = make([][]int, n+1)
    for i := range matrix {
        matrix[i] = make([]int, m+1)
        for j := range matrix[i] {
            matrix[i][j] = -1
        }
    }
    return matrix
}