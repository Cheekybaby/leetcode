func removeDuplicates(nums []int) int {
    i, j := 1, 1
    for ; j < len(nums); j++ {
        if nums[j] != nums[j-1] {
            nums[i] = nums[j]
            i++
        }
    }

    return i
}