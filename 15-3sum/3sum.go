func threeSum(nums []int) [][]int {
    sort.Ints(nums)
    var triplets [][]int
    for i := range nums {
        if i != 0 && nums[i] == nums[i-1] {
            continue
        }

        l, r := i + 1, len(nums)-1
        for l < r {
            sum := nums[i] + nums[l] + nums[r]

            if sum == 0 { // We found a triplet
                triplets = append(triplets, []int{nums[i], nums[l], nums[r]})


                l++
                r--

                for l < r && nums[l] == nums[l-1] {
                    l++
                }
                for l < r && nums[r] == nums[r+1] {
                    r--
                }
            } else if sum > 0 {
                r--
            } else {
                l++
            }
        }
    }

    return triplets
}