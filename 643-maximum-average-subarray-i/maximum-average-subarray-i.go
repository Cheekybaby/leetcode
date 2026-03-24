func findMaxAverage(nums []int, k int) float64 {
    var max_avg float64 = -math.MaxFloat64
    var sum int
    j := 0
    for i := 0; i < len(nums); i++ {
        sum += nums[i]
        win_len := i - j + 1
        
        for win_len > k {
            sum -= nums[j]
            j++
            win_len = i - j + 1
        }

        if win_len == k {
            avg := float64(sum) / float64(k)
            max_avg = max(max_avg, avg)
        }
    }

    return max_avg
}