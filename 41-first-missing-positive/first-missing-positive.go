func firstMissingPositive(nums []int) int {
    n := len(nums)
    for i := range nums {
        if nums[i] <= 0 || nums[i] > n {
            nums[i] = n+1
        }
    }

    for i := 0; i < n; i++ {
        num := abs(nums[i])
        if num > n {
            continue
        }
        if nums[num-1] > 0 {
            nums[num-1] *= -1
        }
    }

    for i := 0; i < n; i++ {
        if nums[i] >= 0 {
            return i + 1
        }
    }

    return n + 1
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}