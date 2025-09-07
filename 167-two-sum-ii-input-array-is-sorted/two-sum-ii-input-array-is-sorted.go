func twoSum(nums []int, target int) []int {
    i, j := 0, len(nums)-1
    for i < j {
        sum := nums[i] + nums[j]

        if sum == target {
            return []int{i+1, j+1}
        } else if sum > target {
            j--
        } else {
            i++
        }
    }

    return []int{j+1, i+1}
}