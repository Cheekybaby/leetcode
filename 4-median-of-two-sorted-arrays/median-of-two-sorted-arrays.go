func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    merged := []int{}

    i, j := 0, 0

    for i < len(nums1) || j < len(nums2) {
        x := getVal(nums1, i)
        y := getVal(nums2, j)

        if x < y {
            merged = append(merged, x)
            i++
        } else {
            merged = append(merged, y)
            j++
        }
    }

    n := len(merged)

    if (n & 1) == 1 {
        return float64(merged[n/2])
    }
    return float64(merged[n/2] + merged[(n/2) - 1]) / float64(2)
}

func getVal(nums []int, idx int) int {
    if idx < len(nums) { return nums[idx] }
    return math.MaxInt
}