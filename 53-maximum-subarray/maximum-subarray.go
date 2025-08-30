func maxSubArray(nums []int) int {
    maxSum, currSum := math.MinInt, 0
    for i := range nums {
        currSum = max(currSum + nums[i], nums[i])

        maxSum = max(currSum, maxSum)

        if currSum < 0 {
            currSum = 0
        }
    }
    return maxSum
}