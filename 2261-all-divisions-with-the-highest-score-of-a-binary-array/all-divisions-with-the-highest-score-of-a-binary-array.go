func maxScoreIndices(nums []int) []int {
    n := len(nums)
    ones := 0
    for i := range nums {
        if nums[i] == 1 { ones++ }
    }

    ans := []int{}
    zeros := 0
    max_div := 0
    for i := range nums {
        div_score := zeros + ones
        if div_score > max_div {
            max_div = div_score
            ans = []int{i}
        } else if div_score == max_div {
            ans = append(ans, i)
        }

        if nums[i] == 1 { ones-- }
        if nums[i] == 0 { zeros++ }
    }

    if zeros > max_div {
        ans = []int{n}
    } else if zeros == max_div {
        ans = append(ans, n)
    }

    return ans
}