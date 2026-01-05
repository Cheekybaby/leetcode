func checkPattern(pattern, subarray []int) bool {
    i, j := 0, 0
    for i < len(pattern) && j < len(subarray)-1 {
        if pattern[i] == 1 {
            if subarray[j] >= subarray[j+1] { return false }
        } else if pattern[i] == 0 {
            if subarray[j] != subarray[j+1] { return false }
        } else {
            if subarray[j] <= subarray[j+1] { return false }
        }
        j++
        i++
    }
    return true
}

func countMatchingSubarrays(nums []int, pattern []int) int {
    n, m := len(nums), len(pattern)
    subarrays := 0
    k := m + 1
    for i := 0; i < (n - m); i++ {
        subarray := nums[i : i + k]

        // match the pattern
        inPattern := checkPattern(pattern, subarray)
        if inPattern {
            subarrays++
        }
    }

    return subarrays
}