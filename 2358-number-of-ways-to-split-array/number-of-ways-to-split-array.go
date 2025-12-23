func waysToSplitArray(nums []int) int {
    tot_sum := 0
    for _, num := range nums {
        tot_sum += num
    }
    sum := 0
    split := 0
    for i := 0; i < len(nums)-1; i++ {
        sum += nums[i]

        if sum >= (tot_sum - sum) {
            split++
        }
    }

    return split
}