func maximumGap(nums []int) int {
    if len(nums) < 2 {
        return 0
    }

    sort.Ints(nums)
    
    max_diff := 0
    for i := 0; i < len(nums)-1; i++ {
        diff := nums[i+1] - nums[i]

        max_diff = max(max_diff, diff)
    }
    
    return max_diff
}