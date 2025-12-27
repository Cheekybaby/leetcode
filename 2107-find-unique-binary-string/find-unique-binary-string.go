func findDifferentBinaryString(nums []string) string {
    n := len(nums)
    ans := make([]byte, n)

    for i := range nums {
        char := nums[i][i]

        if char == '1' {
            ans[i] = '0'
        } else {
            ans[i] = '1'
        }
    }

    return string(ans)
}