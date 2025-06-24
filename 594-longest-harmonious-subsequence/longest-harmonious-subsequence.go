func findLHS(nums []int) int {
    sort.Ints(nums)
    maxlen, i := 0, 0
    for j:=0; j<len(nums); j++ {
        if nums[j] - nums[i] == 1 {
            maxlen = max(maxlen, (j-i+1))
        }
        for nums[j] - nums[i] > 1 {
            i++
        }
    }
    return maxlen;
}