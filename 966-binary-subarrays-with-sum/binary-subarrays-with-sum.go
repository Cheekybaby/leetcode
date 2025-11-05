func subarrays(nums []int, goal int) int {
    total := 0
    i, j := 0, 0
    sum := 0

    for j < len(nums) {
        sum += nums[j]

        if sum <= goal {
            total += (j-i+1)
        } else {
            for i < j && sum > goal {
                sum -= nums[i]
                i++
            }

            if sum <= goal {
                total += (j-i+1)
            }
        }
        j++
    }

    return total
}

func numSubarraysWithSum(nums []int, goal int) int {
    longer := subarrays(nums, goal)
    shorter := subarrays(nums, goal-1)

    return longer - shorter
}