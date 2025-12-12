func minAddToMakeValid(s string) int {
    var st []byte
    for i := range s {
        char := s[i]

        if char == '(' {
            st = append(st, char)
        } else {
            if len(st) == 0 {
                st = append(st, char)
                continue
            }
            top := st[len(st)-1]
            if top == '(' {
                st = st[:len(st)-1]
            } else {
                st = append(st, char)
            }
        }
    }

    return len(st)
}