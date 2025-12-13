func minSteps(s string, t string) int {
    freq := make([]int, 26)

    for i := range s {
        idx := int(s[i] - 'a')
        freq[idx]++
    }

    for i := range t {
        idx := int(t[i] - 'a')
        freq[idx]--
    }

    ops := 0
    for i := range freq {
        ops += abs(freq[i])
    }

    return ops
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}