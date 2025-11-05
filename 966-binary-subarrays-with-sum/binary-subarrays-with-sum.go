func numSubarraysWithSum(nums []int, goal int) int {
    prefix := map[int]int{}

    total := 0
    sum := 0

    for i := range nums {
        sum += nums[i]

        if sum == goal {
            total++
        }

        if val, ok := prefix[sum - goal]; ok {
            total += val
        }

        prefix[sum]++
    }

    return total
}