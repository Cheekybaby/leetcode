func alternatingSubarray(nums []int) int {
    max_len := 0
    for i := 0; i < len(nums)-1; i++ {
        j := i + 1
        positive := true
        for j < len(nums) {
            if positive == true && (nums[j] - nums[j-1]) == 1 {
                j+=1
            } else if positive == false && (nums[j] - nums[j-1]) == -1 {
                j+=1
            } else {
                break
            }
            positive = !positive
        }
        len := j - i
        max_len = max(len, max_len)
    }

    if max_len < 2 {
        return -1
    }

    return max_len
}