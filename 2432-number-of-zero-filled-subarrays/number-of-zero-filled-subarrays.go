func zeroFilledSubarray(nums []int) int64 {
    ans := int64(0)
    for i := 0; i < len(nums);  {
        if nums[i] == 0 {
            j := i
            for j < len(nums) && nums[j] == 0 {
                j++
            }
            n := int64(j - i)
            ans += ((n * (n + 1))/2)
            i = j
        } else {
            i++
        }
    }

    return ans
}