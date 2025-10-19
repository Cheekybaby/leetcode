func removeDuplicates(nums []int) int {
    cnt, k, i := 1, 2, 1
    for j := 1; j < len(nums); j++ {
        if nums[j] == nums[j-1] {
            if cnt < k {
                nums[i] = nums[j]
                i++
            }
            cnt++
        } else {
            nums[i] = nums[j]
            cnt = 1
            i++
        }
    }

    return i
}