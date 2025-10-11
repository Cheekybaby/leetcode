func rob(nums []int) int {
    n := len(nums)

    f := 0
    s := nums[n-1]

    for i := n-2; i >= 0; i-- {
        tmp := max(nums[i] + f, s)
        f = s
        s = tmp
    }
    return s
}