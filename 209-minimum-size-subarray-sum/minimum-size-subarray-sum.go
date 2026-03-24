func minSubArrayLen(target int, nums []int) int {
    var min_len, sum, j int = len(nums)+1, 0, 0
    for i := 0; i < len(nums); i++ {
        sum += nums[i]

        win_len := i - j + 1

        for j <= i && sum >= target {
            min_len = min(min_len, win_len)
            sum -= nums[j]
            j++
            win_len = i - j + 1
        }
    }

    if min_len == len(nums) + 1 { return 0 }

    return min_len
}