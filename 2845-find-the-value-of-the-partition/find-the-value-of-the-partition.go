func findValueOfPartition(nums []int) int {
    sort.Ints(nums)
    min_val := math.MaxInt
    for i := 1; i < len(nums); i++ {
        diff := nums[i] - nums[i-1]
        min_val = min(min_val, diff)
    }

    return min_val
}