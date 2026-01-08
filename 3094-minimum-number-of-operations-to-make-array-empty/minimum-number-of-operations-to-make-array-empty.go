func minOperations(nums []int) int {
    freq := map[int]int{}

    for _, num := range nums {
        freq[num]++
    }

    ops := 0
    for _, val := range freq {
        if val == 1 { return -1 }

        if val % 3 == 0 {
            ops += (val / 3)
        } else if val % 3 == 2 {
            ops += ((val / 3) + 1)
        } else {
            val -= 4
            ops += 2
            ops += (val / 3)
        }
    }

    return ops
}