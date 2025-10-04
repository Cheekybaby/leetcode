func maxProduct(nums []int) int {
    max_prod := math.MinInt
    curr_max, curr_min := 1, 1

    for i := 0; i < len(nums); i++ {
        if nums[i] < 0 {
            curr_max, curr_min = curr_min, curr_max
        }

        curr_max = max(curr_max*nums[i], nums[i])
        curr_min = min(curr_min*nums[i], nums[i])

        max_prod = max(max_prod, curr_max)
    }

    return max_prod
}