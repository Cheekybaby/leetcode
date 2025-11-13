func maximumTripletValue(nums []int) int64 {
    prefix := make([]int, len(nums))
    suffix := make([]int, len(nums))

    prefix[0] = nums[0]
    suffix[len(nums)-1] = nums[len(nums)-1]

    for i := 1; i < len(nums); i++ {
        prefix[i] = max(prefix[i-1], nums[i])
    }
    for i := len(nums)-2; i >= 0; i-- {
        suffix[i] = max(suffix[i+1], nums[i])
    }

    max_value := int64(0)

    for i := 1; i < len(nums)-1; i++ {
        value := int64(prefix[i-1] - nums[i]) * int64(suffix[i+1])

        max_value = max(max_value, value)
    }

    return max_value
}