func maximumSum(nums []int) int {
    var sum_digits [82]int
    max_sum := -1
    var sum, n int
    for i := range nums {
        for sum, n = 0, nums[i]; n > 0; n/=10 {
            sum += (n%10)
        }

        if sum_digits[sum] == 0 {
            sum_digits[sum] = nums[i]
        } else {
            max_sum = max(max_sum, (sum_digits[sum] + nums[i]))

            if nums[i] > sum_digits[sum] {
                sum_digits[sum] = nums[i]
            }
        }
    }

    return max_sum
}