func maxSubArray(nums []int) int {
    return helper(nums, 0, len(nums)-1)
}

func helper(nums []int, left, right int) int {
    if left == right {
        return nums[left]
    }

    mid := (left + right)/2

    left_sum := helper(nums, left, mid)
    right_sum := helper(nums, mid+1, right)
    cross_sum := crossSum(nums, left, mid, right)

    return max(left_sum, max(right_sum, cross_sum))
}

func crossSum(nums []int, left, mid, right int) int {
    left_sum := math.MinInt
    sum := 0

    for i := mid; i >= left; i-- {
        sum += nums[i]
        left_sum = max(left_sum, sum)
    }

    right_sum := math.MinInt
    sum = 0
    
    for i := mid + 1; i <= right; i++ {
        sum += nums[i]
        right_sum = max(right_sum, sum)
    }

    return left_sum + right_sum
}