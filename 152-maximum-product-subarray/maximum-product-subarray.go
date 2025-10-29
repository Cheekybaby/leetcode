func maxProduct(nums []int) int {
    max_product := math.MinInt
    curr_max, curr_min := 1, 1

    for i := range nums {
        if nums[i] < 0 {
            curr_max, curr_min = curr_min, curr_max
        }

        curr_max = max(curr_max * nums[i], nums[i])
        curr_min = min(curr_min * nums[i], nums[i])

        max_product = max(max_product, curr_max)
    }

    return max_product
}