func maxScore(nums []int) int {
    sort.Slice(nums, func (i, j int) bool {
        return nums[i] > nums[j]
    })

    for i := 1; i < len(nums); i++ {
        nums[i] += nums[i-1]
    }
    i := 0
    for i = 0; i < len(nums); i++ {
        if nums[i] <= 0 {
            break
        }
    }
    return i
}