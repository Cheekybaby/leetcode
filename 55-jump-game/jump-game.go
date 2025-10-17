func canJump(nums []int) bool {
    max_reach := 0
    for i := 0; i < len(nums)-1; i++ {
        if i > max_reach {
            return false
        }

        max_reach = max(max_reach, i + nums[i])
    }

    if max_reach >= len(nums)-1 {
        return true
    }
    return false
}