func isAnagram(s string, t string) bool {
    if len(s) != len(t) {
        return false
    }

    freq := make([]int, 26)

    for i := range s {
        freq[int(s[i] - 'a')]++
    }
    
    for i := range t {
        freq[int(t[i] - 'a')]--
    }

    for _, f := range freq {
        if f != 0 {
            return false
        }
    }
    return true
}