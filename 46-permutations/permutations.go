func solve(nums []int, idx int, temp []int, ans *[][]int, set map[int]int) {
    if idx == len(nums) {
        tmp := make([]int, len(temp))
        copy(tmp, temp)
        *ans = append(*ans, tmp)

        return
    }

    for i := range nums {
        if _, ok := set[nums[i]]; !ok {
            temp = append(temp, nums[i])
            set[nums[i]] = 1
            solve(nums, idx+1, temp, ans, set)
            delete(set, nums[i])
            temp = temp[:len(temp)-1]
        }
    }
}

func permute(nums []int) [][]int {
    var temp []int
    var ans [][]int
    set := make(map[int]int)
    solve(nums, 0, temp, &ans, set)

    return ans
}