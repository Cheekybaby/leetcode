func findLHS(nums []int) int {
    sort.Ints(nums)
    j, maxlen := 0, 0
    for i:=0; i<len(nums); i++ {
        if nums[i] - nums[j] == 1 {
            maxlen = max(maxlen, (i - j + 1))
        }
        for nums[i] - nums[j] > 1 {
            j++
        }
    }

    return maxlen
}