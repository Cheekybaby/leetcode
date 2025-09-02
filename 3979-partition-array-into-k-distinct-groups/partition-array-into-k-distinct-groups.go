func partitionArray(nums []int, k int) bool {
    if len(nums) % k != 0 {
        return false
    }

    groups := len(nums)/k
    freq := make(map[int]int)
    for i := range nums {
        freq[nums[i]]++
    }

    for _, f := range freq {
        if f > groups {
            return false
        }
    }

    return true
}