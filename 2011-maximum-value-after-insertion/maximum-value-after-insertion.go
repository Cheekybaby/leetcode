func maxValue(n string, x int) string {
    ch := byte(x) + '0'
    idx := len(n)
    if n[0] == '-' {
        for i := len(n)-1; i >= 1; i-- {
            if n[i] > ch {
                idx = i
            }
        }
    } else {
        for i := len(n)-1; i >= 0; i-- {
            if n[i] < ch {
                idx = i
            }
        }
    }
    ans := make([]byte, len(n) + 1)
    ans[idx] = ch

    for i := 0; i < idx; i++ {
        ans[i] = n[i]
    }
    for i := idx; i < len(n); i++ {
        ans[i+1] = n[i]
    }

    return string(ans)
}