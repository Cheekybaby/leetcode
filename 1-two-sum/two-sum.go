func twoSum(nums []int, target int) []int {
    seen := map[int]int{}
    for i, num := range nums {
        toFind := target - num

        if j, ok := seen[toFind]; ok {
            return []int{j, i}
        }

        seen[num] = i
    }

    return []int{}
}