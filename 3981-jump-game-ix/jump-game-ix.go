func maxValue(nums []int) []int {
    n := len(nums)
    ans, pref, suff := make([]int, n), make([]int, n), make([]int, n)

    pref[0] = nums[0]
    suff[n-1] = nums[n-1]

    for i:=1; i<n; i++ {
        pref[i] = max(nums[i], pref[i-1])
    }
    for i:=n-2; i>=0; i-- {
        suff[i] = min(nums[i], suff[i+1])
    }

    ans[n-1] = pref[n-1]

    for i:=n-2; i>=0; i-- {
        ans[i] = pref[i]

        if suff[i+1] < pref[i] {
            ans[i] = ans[i+1]
        }
    }

    return ans
}