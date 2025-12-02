func sortColors(nums []int)  {
    i, j, k := 0, 0, len(nums)-1

    for j <= k {
        if nums[j] == 0 {
            nums[i], nums[j] = nums[j], nums[i]
            i++
            j++
        } else if nums[j] == 2 {
            nums[j], nums[k] = nums[k], nums[j]
            k--
        } else {
            j++
        }
    }
}