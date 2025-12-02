func twoSum(nums []int, target int) []int {
    seen := make(map[int]int)
    for i, num := range nums {
        toFind := target - num
        if idx, ok := seen[toFind]; ok {
            return []int{idx, i}
        }
        seen[num] = i
    }

    return []int{-1,-1}
}