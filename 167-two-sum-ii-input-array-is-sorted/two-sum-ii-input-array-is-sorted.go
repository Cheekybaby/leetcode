func twoSum(numbers []int, target int) []int {
    for i := range numbers {
        toFind := target - numbers[i]

        idx := binarySearch(numbers, i+1, toFind)

        if idx != -1 {
            return []int{i+1, idx+1}
        }
    }

    return []int{-1,-1}
}
func binarySearch(nums []int, st, target int) int {
    end := len(nums)-1
    for st <= end {
        mid := st + (end - st)/2

        if nums[mid] == target {
            return mid
        } else if nums[mid] > target {
            end = mid - 1
        } else {
            st = mid + 1
        }
    }

    return -1
}