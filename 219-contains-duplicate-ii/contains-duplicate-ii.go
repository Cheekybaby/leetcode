func containsNearbyDuplicate(nums []int, k int) bool {
    mpp := make(map[int]int)

    for i, num := range nums {
        if val, ok := mpp[num]; ok {
            if abs(val, i) <= k {
                return true
            }
        }
        mpp[num] = i
    }

    return false
}

func abs(a, b int) int {
    if a >= b {
        return a-b
    }
    return b-a
}