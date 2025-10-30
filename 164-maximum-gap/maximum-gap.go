func maximumGap(nums []int) int {
    if len(nums) < 2 {
        return 0
    }

    minimum, maximum := nums[0], nums[0]

    for i := range nums {
        minimum = min(minimum, nums[i])
        maximum = max(maximum, nums[i])
    }

    if minimum == maximum {
        return 0
    }

    gap := ((maximum - minimum)/(len(nums) - 1)) + 1
    capacity := len(nums)-1

    bucket_min := make([]int, capacity)
    bucket_max := make([]int, capacity)

    for i := range capacity {
        bucket_min[i] = math.MaxInt
        bucket_max[i] = math.MinInt
    }

    for _, num := range nums {
        if num == maximum || num == minimum {
            continue
        }

        idx := (num - minimum) / gap

        bucket_min[idx] = min(num, bucket_min[idx])
        bucket_max[idx] = max(num, bucket_max[idx])
    }

    max_gap := math.MinInt
    prev := minimum

    for i := range capacity {
        if bucket_min[i] == math.MaxInt && bucket_max[i] == math.MinInt {
            continue
        }
        max_gap = max(max_gap, bucket_min[i] - prev)
        prev = bucket_max[i]
    }

    max_gap = max(max_gap, maximum - prev)

    return max_gap
}