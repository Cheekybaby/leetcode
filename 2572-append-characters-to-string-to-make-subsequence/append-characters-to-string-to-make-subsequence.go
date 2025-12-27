func appendCharacters(s string, t string) int {
    j := 0
    for i := range s {
        if s[i] == t[j] {
            j++
        }
        if j >= len(t) {
            break
        }
    }


    return len(t) - j
}