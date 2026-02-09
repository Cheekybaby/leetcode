func isAnagram(s string, t string) bool {
    if len(s) != len(t) { return false }

    freq := make([]int, 26)
    for i := range s {
        s_idx := int(s[i] - 'a')
        t_idx := int(t[i] - 'a')

        freq[s_idx]++
        freq[t_idx]--
    }

    for _, f := range freq {
        if f != 0 { return false }
    }

    return true
}