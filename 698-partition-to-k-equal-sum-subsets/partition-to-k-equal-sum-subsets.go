func solve(nums []int, idx int, res_arr []int, target int) bool {
    if idx == len(nums) { return true }

    for i := range res_arr {
        if res_arr[i] + nums[idx] > target { continue }
        if i > 0 && res_arr[i] == res_arr[i-1] { continue }
        res_arr[i] += nums[idx]
        if solve(nums, idx+1, res_arr, target) { return true }
        res_arr[i] -= nums[idx]
    }

    return false
}

func canPartitionKSubsets(nums []int, k int) bool {
    total := 0
    for _, num := range nums {
        total += num
    }

    if (total % k) != 0 {
        return false
    }

    target := total / k
    sort.Slice(nums, func (i, j int) bool {
        return nums[i] > nums[j]
    })

    res_arr := make([]int, k)
    return solve(nums, 0, res_arr, target)
}