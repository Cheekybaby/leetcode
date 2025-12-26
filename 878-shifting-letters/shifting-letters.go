var alphabets = []byte{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}

func shiftingLetters(s string, shifts []int) string {
    for i := len(shifts)-2; i >= 0; i-- {
        shifts[i] += shifts[i+1]
    }
    ans := []byte(s)
    for i := range ans {
        idx := int(ans[i] - 'a')
        new_idx := (idx + shifts[i]) % 26
        ans[i] = alphabets[new_idx]
    }

    return string(ans)
}