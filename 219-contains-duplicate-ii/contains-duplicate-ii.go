func containsNearbyDuplicate(nums []int, k int) bool {
    i := 0
    for i < len(nums) {
        j := i + 1
        for j <= i+k && j < len(nums) {
            if nums[i] == nums[j] {
                return true
            }
            j++
        }
        i++
    }

    return false
}