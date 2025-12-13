func occurrencesOfElement(nums []int, queries []int, x int) []int {
    var occur []int
    for i := range nums {
        if nums[i] == x {
            occur = append(occur, i)
        }
    }

    ans := make([]int, len(queries))
    for i, idx := range queries {
        if idx-1 >= len(occur) {
            ans[i] = -1
        } else {
            ans[i] = occur[idx-1]
        }
    }

    return ans
}