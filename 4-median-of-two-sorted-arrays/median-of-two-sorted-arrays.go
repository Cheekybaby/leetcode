func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    size := len(nums1) + len(nums2)
    nums := make([]int, size)

    i, j, k := 0, 0, 0

    for i < len(nums1) && j < len(nums2) {
        if nums1[i] <= nums2[j] {
            nums[k] = nums1[i]
            i+=1
        } else {
            nums[k] = nums2[j]
            j+=1
        }
        k+=1
    }

    for i < len(nums1) {
        nums[k] = nums1[i]
        i+=1
        k+=1
    }
    for j < len(nums2) {
        nums[k] = nums2[j]
        j+=1
        k+=1
    }

    
    if isOdd(size) {
        return float64(nums[size/2])
    }
    return float64((nums[size/2] + nums[(size/2)-1]))/2
}

func isOdd(size int) bool {
    if size % 2 == 0 {
        return false
    }
    return true
}