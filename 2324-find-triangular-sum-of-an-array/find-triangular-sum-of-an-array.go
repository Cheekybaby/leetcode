func triangularSum(nums []int) int {
    for len(nums) > 1 {
        new_nums := make([]int, len(nums)-1)
        for i := range len(new_nums) {
            new_nums[i] = (nums[i] + nums[i+1]) % 10
        }
        nums = new_nums
    }

    return nums[0]
}