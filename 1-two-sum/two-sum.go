func twoSum(nums []int, target int) []int {
    mpp := make(map[int]int)

    for i, num := range nums {
        toFind := target - num

        if value, ok := mpp[toFind]; ok {
            return []int{value, i}
        }
        mpp[num] = i
    }

    return []int{-1,-1}
}