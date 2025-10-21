func solve(nums []int, idx int, temp []int, ans *[][]int) {
    tmp := make([]int, len(temp))
    copy(tmp, temp)
    *ans = append(*ans, tmp)

    for i := idx; i < len(nums); i++ {
        if i > idx && nums[i] == nums[i-1] {
            continue
        }

        temp = append(temp, nums[i])
        solve(nums, i+1, temp, ans)
        temp = temp[:len(temp)-1]
    }
}

func subsetsWithDup(nums []int) [][]int {
    sort.Ints(nums)

    var temp []int
    var ans [][]int

    solve(nums, 0, temp, &ans)

    return ans
}