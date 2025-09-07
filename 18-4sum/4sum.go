func fourSum(nums []int, target int) [][]int {
    sort.Ints(nums)
    var quads [][]int
    for i := range nums {
        if i > 0 && nums[i] == nums[i-1] {
            continue
        }

        for j := i+1; j < len(nums); j++ {
            if j > i+1 && nums[j] == nums[j-1] {
                continue
            }

            l, r := j + 1, len(nums)-1

            for l < r {
                sum := int64(nums[i]) + int64(nums[j]) + int64(nums[l]) + int64(nums[r])

                if sum == int64(target) {
                    quads = append(quads, []int{nums[i], nums[j], nums[l], nums[r]})

                    l++
                    r--

                    for l < r && nums[l] == nums[l-1] {
                        l++
                    }
                    for l < r && nums[r] == nums[r+1] {
                        r--
                    }
                } else if sum > int64(target) {
                    r--
                } else {
                    l++
                }
            }
        }
    }
    return quads
}