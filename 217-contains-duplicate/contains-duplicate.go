func containsDuplicate(nums []int) bool {
    mpp := make(map[int]bool)

    for _, val := range nums {
        if _, ok := mpp[val]; ok {
            return true
        }
        mpp[val] = true
    }

    return false
}