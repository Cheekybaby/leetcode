func minSteps(s string, t string) int {
    freq_s := make([]int, 26)
    for i := range s {
        freq_s[int(s[i]-'a')]++
    }
    ops := 0
    for i := range t {
        if freq_s[int(t[i]-'a')] > 0 {
            freq_s[int(t[i]-'a')]--
            continue
        }
        ops++
    }

    return ops
}