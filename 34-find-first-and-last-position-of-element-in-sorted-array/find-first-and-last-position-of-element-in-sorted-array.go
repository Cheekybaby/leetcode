func searchRange(nums []int, target int) []int {
    l := lower_bound(nums, target)
    r := upper_bound(nums, target)

    return []int{l, r}
}

func lower_bound(nums []int, target int) int {
    l, r := 0, len(nums)-1
    for l <= r {
        mid := l + (r - l) / 2
        
        if nums[mid] == target {
            if mid == 0 || nums[mid] != nums[mid-1] {
                return mid
            } else {
                r = mid - 1
            }
        } else if nums[mid] > target {
            r = mid - 1
        } else {
            l = mid + 1
        }
    }
    return -1
}

func upper_bound(nums []int, target int) int {
    l, r := 0, len(nums)-1
    for l <= r {
        mid := l + (r - l) / 2
        
        if nums[mid] == target {
            if mid == len(nums)-1 || nums[mid] != nums[mid+1] {
                return mid
            } else {
                l = mid + 1
            }
        } else if nums[mid] > target {
            r = mid - 1
        } else {
            l = mid + 1
        }
    }
    return -1
}
