func minimumDeletions(nums []int) int {
    n := len(nums)
    mini, maxi := math.MaxInt, math.MinInt
    min_idx, max_idx := 0, 0

    for i, num := range nums {
        if num < mini {
            mini = num
            min_idx = i
        }
        if num > maxi {
            maxi = num
            max_idx = i
        }
    }
    
    del_from_left := max(min_idx, max_idx) + 1
    del_from_right := n - min(min_idx, max_idx)
    del_from_both := min(min_idx, max_idx) + 1 + (n - max(min_idx, max_idx))

    return min(del_from_left, min(del_from_right, del_from_both))
}