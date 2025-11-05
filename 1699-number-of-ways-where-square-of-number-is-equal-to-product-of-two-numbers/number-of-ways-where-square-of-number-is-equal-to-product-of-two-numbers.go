func numTriplets(nums1 []int, nums2 []int) int {
    prod1, prod2 := make(map[int]int), make(map[int]int)

    for i := 0; i < len(nums1); i++ {
        for j := i+1; j < len(nums1); j++ {
            prod := nums1[i] * nums1[j]

            prod1[prod]++
        }
    }

    for i := 0; i < len(nums2); i++ {
        for j := i+1; j < len(nums2); j++ {
            prod := nums2[i] * nums2[j]

            prod2[prod]++
        }
    }

    cnt := 0
    for _, val := range nums1 {
        toFind := val * val

        if f, ok := prod2[toFind]; ok {
            cnt += f
        }
    }
    for _, val := range nums2 {
        toFind := val * val

        if f, ok := prod1[toFind]; ok {
            cnt += f
        }
    }

    return cnt
}