func twoSum(nums []int, target int) []int {
    mpp := make(map[int]int)

    for i:=0; i<len(nums); i++ {
        toFind := target - nums[i]
        if val, ok := mpp[toFind]; ok {
            return []int{val, i}
        }
        mpp[nums[i]] = i
    }

    return []int{-1,-1}
}