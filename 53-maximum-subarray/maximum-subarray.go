func maxSubArray(nums []int) int {
    max_sum := math.MinInt
    sum := 0
    for i := 0; i < len(nums); i++ {
        sum = max(nums[i], sum + nums[i])
        max_sum = max(max_sum, sum)

        if sum < 0 {
            sum = 0
        }
    }
    return max_sum
}