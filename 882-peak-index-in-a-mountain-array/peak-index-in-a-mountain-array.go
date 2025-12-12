func peakIndexInMountainArray(nums []int) int {
    i, j := 1, len(nums)-2
    for i <= j {
        mid := i + (j - i)/2

        if nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1] {
            return mid
        } else if nums[mid] > nums[mid-1] && nums[mid] < nums[mid+1] {
            i = mid + 1
        } else {
            j = mid -1
        }
    }

    return -1
}