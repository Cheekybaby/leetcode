func maxSubArray(nums []int) int {
    max_sum := math.MinInt
    sum := 0
    for i := range nums {
        sum = max(sum + nums[i], nums[i])

        max_sum = max(max_sum, sum)

        if sum < 0 { sum = 0 }
    }

    return max_sum
}