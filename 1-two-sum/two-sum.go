func twoSum(nums []int, target int) []int {
    var ans []int
    mpp := make(map[int]int)

    for i:=0; i<len(nums); i++ {
        toFind := target - nums[i]

        value, ok := mpp[toFind]

        if ok {
            ans = append(ans, value, i)
            return ans
        }
        mpp[nums[i]] = i
    }

    ans = append(ans, -1, -1)
    return ans
}