func stringHash(s string, k int) string {
    res := make([]byte, len(s)/k)
    l := 0
    for i := 0; i < len(s); i+=k {
        sum := 0
        for j := i; j < i+k; j++ {
            sum += int(s[j] - 'a')
        }
        sum %= 26
        char := byte(sum + int('a'))

        res[l] = char
        l++
    }

    return string(res)
}