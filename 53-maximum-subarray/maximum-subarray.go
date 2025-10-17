func maxSubArray(nums []int) int {
    sum := 0
    max_sum := math.MinInt
    for i := range nums {
        sum = max(sum + nums[i], nums[i])
        max_sum = max(sum, max_sum)

        if sum < 0 {
            sum = 0
        }
    }

    return max_sum
}