func maxOperations(s string) int {
    cnt, op := 0, 0
    for i := 0; i < len(s); i++ {
        if s[i] == '0' {
            op += cnt
            for i < len(s) && s[i] != '1' {
                i++
            }
        }
        cnt++
    }

    return op
}