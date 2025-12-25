func removeStars(s string) string {
    var st []byte
    for i := range s {
        if s[i] == '*' {
            st = st[:len(st)-1]
        } else {
            st = append(st, s[i])
        }
    }

    return string(st)
}