func maxSubarraySumCircular(nums []int) int {
    globalMax, globalMin := nums[0], nums[0]
    currMax, currMin := 0, 0
    sum := 0

    for i := range nums {
        currMax = max(currMax + nums[i], nums[i])
        currMin = min(currMin + nums[i], nums[i])

        sum += nums[i]

        globalMax = max(globalMax, currMax)
        globalMin = min(globalMin, currMin)
    }

    if globalMax > 0 {
        return max(globalMax, sum - globalMin)
    }
    return globalMax
}