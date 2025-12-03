func subarraySum(nums []int, k int) int {
    sum := 0
    all_sum := map[int]int{
        0 : 1,
    }
    subarray := 0
    for i := range nums {
        sum += nums[i]
        complement := sum - k

        if val, ok := all_sum[complement]; ok {
            subarray += val
        }

        all_sum[sum] += 1
    }

    return subarray
}