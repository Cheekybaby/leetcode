func solve(nums []int, idx int, temp []int, ans *[][]int, visited []bool) {
    if idx == len(nums) {
        tmp := make([]int, len(temp))
        copy(tmp, temp)
        *ans = append(*ans, tmp)

        return
    }

    for i := 0; i < len(nums); i++ {
        if visited[i] || (i > 0 && nums[i] == nums[i-1] && !visited[i-1]) {
            continue
        }

        temp = append(temp, nums[i])
        visited[i] = true
        solve(nums, idx+1, temp, ans, visited)
        visited[i] = false
        temp = temp[:len(temp)-1]
    }
}

func permuteUnique(nums []int) [][]int {
    sort.Slice(nums, func(i, j int) bool {
        return nums[i] < nums[j]
    })
    var ans [][]int
    var temp []int
    visited := make([]bool, len(nums))

    solve(nums, 0, temp, &ans, visited)

    return ans
}