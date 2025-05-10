func twoSum(nums []int, target int) []int {
    appearedMap := make(map[int]int)
    for index, num := range nums {
        toFind := target - num
        if val, ok := appearedMap[toFind]; ok {
            return []int{val, index}
        }
        appearedMap[num] = index
    }

    return []int{-1,-1}
}