func threeSumClosest(nums []int, target int) int {
    sort.Ints(nums)
    closest := 0
    min_diff := math.MaxInt

    for i := range nums {
        if i != 0 && nums[i] == nums[i-1] {
            continue
        }
        l, r := i+1, len(nums)-1
        for l < r {
            sum := nums[i] + nums[l] + nums[r]

            if sum == target {
                return sum
            }

            diff := abs(target - sum)
            // Update the closest
            if diff < min_diff {
                closest = sum
                min_diff = diff
            }
            // Update the pointers
            if sum > target {
                r--
            } else {
                l++
            }
        }
    }

    return closest
}
func abs(x int) int {
    if x < 0 {
        return -1 * x
    }
    return x
}