func minOperations(nums []int) int {
    i, j := 0, 0
    ops := 0
    for j < len(nums) {
        win_len := j - i + 1

        if win_len == 3 {
            if nums[i] == 0 { // This is the operation
                l := i
                for l <= j {
                    nums[l] = 1 - nums[l]
                    l++
                }
                ops++
            }
            i++
        }
        j++
    }

    for i := range nums {
        if nums[i] == 0 {
            return -1
        }
    }

    return ops
}