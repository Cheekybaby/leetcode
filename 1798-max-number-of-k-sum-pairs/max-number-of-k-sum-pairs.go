func maxOperations(nums []int, k int) int {
    ops := 0
    freq := map[int]int{}

    for _, num := range nums {
        freq[num]++
    }

    // fmt.Println(freq)

    for key, val := range freq {
        toFind := k - key

        f, ok := freq[toFind]

        if ok {
            if key == toFind {
                ops += (f / 2)
                delete(freq, key)
                continue
            }

            ops += min(f, val)
            delete(freq, key)
            delete(freq, toFind)
        }
    }

    return ops
}