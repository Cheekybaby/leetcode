func search(nums []int, target int) bool {
    left, right := 0, len(nums)-1

    for left <= right {
        mid := left + (right - left)/2

        if nums[mid] == target {
            return true
        } else if nums[left] == nums[right]  {
            left++
        } else if nums[left] <= nums[mid] {
            if target >= nums[left] && target < nums[mid] {
                right = mid - 1
            } else {
                left = mid + 1
            }
        } else {
            if target <= nums[right] && target > nums[mid] {
                left = mid + 1
            } else {
                right = mid - 1
            }
        }
    }

    return false
}