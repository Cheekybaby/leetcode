func maxSubArray(nums []int) int {
    sum := 0
    max_sum := math.MinInt

    for i := range nums {
        sum = max(nums[i], sum + nums[i])

        max_sum = max(max_sum, sum)

        if sum < 0 {
            sum = 0
        }
    }

    return max_sum
}