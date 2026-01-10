func minimumAverageDifference(nums []int) int {
    n := len(nums)
    tot_sum := 0
    for _, num := range nums {
        tot_sum += num
    }

    min_avg_diff := math.MaxInt
    idx := 0
    sum := 0
    for i, num := range nums {
        sum += num
        
        left := sum / (i + 1)
        right := 0
        if n - i - 1 > 0 {
            right = (tot_sum - sum) / (n - i - 1)
        }
        avg_diff := abs(left - right)

        if avg_diff < min_avg_diff {
            min_avg_diff = avg_diff
            idx = i
        }
    }

    return idx
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}