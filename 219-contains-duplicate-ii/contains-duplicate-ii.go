func containsNearbyDuplicate(nums []int, k int) bool {
    if k == 0 {
        return false
    }
    j := 0
    seen := map[int]int{}
    for i := 0; i < len(nums); i++ {
        curr := nums[i]

        win_len := i - j

        if win_len > k {
            // now shrink the window 
            for win_len > k {
                temp := nums[j]
                delete(seen, temp)
                j++
                win_len = i - j
            }
        }

        // Now check if there are duplicates or not
        if _, ok := seen[curr]; ok {
            return true
        }
        seen[nums[i]]++
    }

    return false
}