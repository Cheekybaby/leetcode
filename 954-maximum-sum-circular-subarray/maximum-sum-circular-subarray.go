func maxSubarraySumCircular(nums []int) int {
    max_sum, min_sum := math.MinInt, math.MaxInt
    curr_max, curr_min := 0, 0
    sum := 0
    for i := 0; i<len(nums); i++ {
        curr_max = max(curr_max + nums[i], nums[i])
        curr_min = min(curr_min + nums[i], nums[i])

        sum += nums[i]

        max_sum = max(max_sum, curr_max)
        min_sum = min(min_sum, curr_min)
    }

    if max_sum > 0 {
        return max(max_sum, sum - min_sum)
    }
    return max_sum
}