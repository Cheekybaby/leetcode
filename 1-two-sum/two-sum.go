func twoSum(nums []int, target int) []int {
    mpp := make(map[int]int)

    for i:=0; i<len(nums); i++ {
        toFind := target - nums[i]
        if value, ok := mpp[toFind]; ok {
            return []int{value, i}
        }
        mpp[nums[i]] = i
    }
    return []int{-1,-1}
}