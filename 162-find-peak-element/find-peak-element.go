func findPeakElement(nums []int) int {
    left, right := 0, len(nums)-1

    for left <= right {
        mid := left + (right - left)/2

        if mid > 0 && nums[mid] < nums[mid-1] {
            right = mid - 1
        } else if mid < len(nums)-1 && nums[mid] < nums[mid+1] {
            left = mid + 1
        } else {
            return mid
        }
    }

    return -1
}