func findMin(nums []int) int {
    min_element := nums[0]
    left, right := 0, len(nums)-1

    for left <= right {
        mid := left + (right - left)/2

        if nums[left] <= nums[right] {
            min_element = min(min_element, nums[left])
            break
        }

        min_element = min(min_element, nums[mid])

        if nums[left] <= nums[mid] {
            left = mid + 1
        } else {
            right = mid - 1
        }
    }

    return min_element
}