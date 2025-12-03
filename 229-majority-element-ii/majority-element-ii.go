func majorityElement(nums []int) []int {
    cand1, cand2 := -1, -1
    vote1, vote2 := 0, 0

    for i := range nums {
        if nums[i] == cand1 {
            vote1++
        } else if nums[i] == cand2 {
            vote2++
        } else if vote1 == 0 {
            cand1 = nums[i]
            vote1 = 1
        } else if vote2 == 0 {
            cand2 = nums[i]
            vote2 = 1
        } else {
            vote1--
            vote2--
        }
    }

    vote1, vote2 = 0, 0
    for _, num := range nums {
        if num == cand1 {
            vote1++
        } else if num == cand2 {
            vote2++
        }
    }

    var majority []int
    if vote1 > len(nums)/3 {
        majority = append(majority, cand1)
    }
    if vote2 > len(nums)/3 {
        majority = append(majority, cand2)
    }

    return majority
}