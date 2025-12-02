func getConcatenation(nums []int) []int {
    n := len(nums)
    ans := make([]int, 2*n)
    for i := 0; i < len(ans); i++ {
        ans[i] = nums[i % n]
    }

    return ans
}