func pivotArray(nums []int, pivot int) []int {
    var lesser, greater []int 
    var equal int

    for _, num := range nums {
        if num < pivot {
            lesser = append(lesser, num)
        } else if num == pivot {
            equal++
        } else {
            greater = append(greater, num)
        }
    }
    k := 0
    for _, less := range lesser {
        nums[k] = less
        k++
    }
    for equal > 0 {
        nums[k] = pivot
        k++
        equal--
    }
    for _, gre := range greater {
        nums[k] = gre
        k++
    }
    return nums
}