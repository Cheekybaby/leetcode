func maxSubarraySumCircular(nums []int) int {
    loc_max, loc_min := 0, 0
    glo_max, glo_min := math.MinInt, math.MaxInt
    sum := 0
    for i := range nums {
        loc_max = max(loc_max + nums[i], nums[i])
        loc_min = min(loc_min + nums[i], nums[i])

        sum += nums[i]

        glo_max = max(glo_max, loc_max)
        glo_min = min(glo_min, loc_min)
    }

    if glo_max > 0 {
        return max(glo_max, sum - glo_min)
    }
    return glo_max
}