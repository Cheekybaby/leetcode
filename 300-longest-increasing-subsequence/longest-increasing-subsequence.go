func lengthOfLIS(nums []int) int {
    var tails []int
    tails = append(tails, nums[0])
    for _, val := range nums {
        idx := binarySearch(tails, val)
        if idx >= len(tails) {
            tails = append(tails, val)
        } else {
            tails[idx] = val
        }
    }

    return len(tails)
}

func binarySearch(nums []int, val int) int {
    l, r := 0, len(nums)-1
    for l <= r {
        mid := l + (r - l)/2
        if nums[mid] >= val {
            r = mid - 1
        } else {
            l = mid + 1
        }
    }

    return l
}