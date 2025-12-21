func matrixSum(nums [][]int) int {
    for i := range nums {
        sort.Ints(nums[i])
    }
    score := 0
    for i := 0; i < len(nums[0]); i++ {
        max_val := 0
        for j := 0; j < len(nums); j++ {
            if nums[j][i] > max_val {
                max_val = nums[j][i]
            }
        }
        score += max_val
    }

    return score
}