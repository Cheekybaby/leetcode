func merge(nums1 []int, m int, nums2 []int, n int)  {
    sorted := make([]int, m+n)
    i, j, k := 0, 0, 0
    for i < m || j < n {
        first, second := math.MaxInt, math.MaxInt
        if i < m {
            first = nums1[i]
        }
        if j < n {
            second = nums2[j]
        }

        if first <= second {
            sorted[k] = first
            i++
        } else {
            sorted[k] = second
            j++
        }
        k++
    }
    copy(nums1, sorted)
}