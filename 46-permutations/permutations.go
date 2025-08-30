func solve(nums []int , ans *[][]int, temp []int, index int, set map[int]int) {
    if index == len(nums) {
        copyTemp := make([]int, len(temp))
        copy(copyTemp, temp)
        *ans = append(*ans, copyTemp)
        return 
    }

    for i := range nums {
        if _, ok := set[nums[i]]; !ok {
            set[nums[i]] = 1
            temp = append(temp, nums[i])
            solve(nums, ans, temp, index + 1, set)
            delete(set, nums[i])
            temp = temp[:len(temp)-1]
        }
    }
}

func permute(nums []int) [][]int {
    var ans [][]int
    var temp []int
    set := make(map[int]int)
    solve(nums, &ans, temp, 0, set)
    return ans
}