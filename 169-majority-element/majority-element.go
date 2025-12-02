func majorityElement(nums []int) int {
    cand := nums[0]
    vote := 1
    for i := 1; i < len(nums); i++ {
        if nums[i] == cand {
            vote++
        } else if nums[i] != cand {
            vote --
        }

        if vote < 0 {
            cand = nums[i]
            vote = 0
        }
    }
    vote = 0
    for _, num := range nums {
        if num == cand {
            vote++
        }
    }

    if vote > (len(nums)/2) {
        return cand
    }
    return -1
}