func waysToMakeFair(nums []int) int {
    even, odd := 0, 0
    for i := 0; i < len(nums); i++ {
        if i % 2 == 0 {
            even += nums[i]
        } else {
            odd += nums[i]
        }
    }
    cnt := 0
    curr_even, curr_odd := 0, 0
    for i := 0; i < len(nums); i++ {
        if i % 2 == 0 {
            even -= nums[i]
        } else {
            odd -= nums[i]
        }

        if curr_even + odd == curr_odd + even {
            cnt++
        }

        if i % 2 == 0 {
            curr_even += nums[i]
        } else {
            curr_odd += nums[i]
        }
    }

    return cnt
}