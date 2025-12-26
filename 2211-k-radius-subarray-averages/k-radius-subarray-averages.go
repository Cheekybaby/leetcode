func getAverages(nums []int, k int) []int {
    radius := make([]int, len(nums))
    for i := range radius {
        radius[i] = -1
    }

    for i := 1; i < len(nums); i++ {
        nums[i] += nums[i-1]
    }

    for i := k; i < len(nums) - k; i++ {
        n := 2 * k + 1
        sum := nums[i+k]

        if i > k {
            sum -= nums[i-k-1]
        }

        average := sum / n
        radius[i] = average
    }

    return radius
}