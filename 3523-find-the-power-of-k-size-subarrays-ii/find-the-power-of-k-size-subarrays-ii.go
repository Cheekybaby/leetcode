func resultsArray(nums []int, k int) []int {
    n := len(nums)
    pref := make([]int, n)
    len := 1

    pref[0] = 1

    for i := 1; i < n; i++ {
        if nums[i] - nums[i-1] == 1 {
            len++
        } else {
            len = 1
        }

        pref[i] = len
    }

    results := make([]int, (n - k + 1))

    for i := k-1; i < n; i++ {
        if pref[i] >= k {
            results[i-(k-1)] = nums[i]
        } else {
            results[i-(k-1)] = -1
        }
    }

    return results
}