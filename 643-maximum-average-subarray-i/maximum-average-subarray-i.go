func findMaxAverage(nums []int, k int) float64 {
    maxAvg := -math.MaxFloat64
    j, sum := 0, 0
    for i:=0; i<len(nums); i++ {
        length := i - j + 1
        sum += nums[i]
        if length == k {
            avg := float64(sum) / float64(k)
            maxAvg = max(maxAvg, avg)
            sum -= nums[j]
            j+=1
        }
    }

    return maxAvg
}