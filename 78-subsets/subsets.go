func solve(nums []int, idx int, temp []int, ans *[][]int) {
    if idx == len(nums) {
        tmp := make([]int, len(temp))
        copy(tmp, temp)
        *ans = append(*ans, tmp)

        return
    }

    temp = append(temp, nums[idx])
    solve(nums, idx+1, temp, ans)
    temp = temp[:len(temp)-1]
    solve(nums, idx+1, temp, ans)
}

func subsets(nums []int) [][]int {
    var temp []int
    var ans [][]int

    solve(nums, 0, temp, &ans)

    return ans
}