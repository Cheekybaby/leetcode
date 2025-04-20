func containsNearbyDuplicate(nums []int, k int) bool {
    i, l := 0, 0
    for i < len(nums) {
        j := i + 1
        for j <= i+k && j < len(nums) {
            if nums[i] == nums[j] {
                return true
            }
            j++
            l++

            if l > 99999 {
                return false
            }
        }
        i++
    }

    return false
}