func sortedSquares(nums []int) []int {
    i, j, k := 0, len(nums)-1, len(nums)-1
    ans := make([]int, len(nums))

    for i <= j {
        left := nums[i] * nums[i]
        right := nums[j] * nums[j]

        if left > right {
            ans[k] = left
            i++
        } else {
            ans[k] = right
            j--
        }
        k--
    }

    return ans
}