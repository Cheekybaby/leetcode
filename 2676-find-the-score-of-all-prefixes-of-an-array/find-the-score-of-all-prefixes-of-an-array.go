func findPrefixScore(nums []int) []int64 {
    ans := make([]int64, len(nums))
    maxi := nums[0]
    for i := 0; i < len(nums); i++ {
        maxi = max(maxi, nums[i])
        ans[i] = int64(maxi + nums[i])

        if i > 0 {
            ans[i] += ans[i-1]
        }
    }

    return ans
}