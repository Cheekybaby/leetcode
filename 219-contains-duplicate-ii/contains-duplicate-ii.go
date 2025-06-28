func containsNearbyDuplicate(nums []int, k int) bool {
    if k == 0 {
        return false
    }
    set := make(map[int]bool)
    j := 0
    for i:=0; i<len(nums); i++ {
        length := i - j
        if length <= k {
            if _, ok := set[nums[i]]; ok {
                return true
            }
            if length == k {
                delete(set, nums[j])
                j+=1
            }
        }
        set[nums[i]] = true
    }
    return false
}