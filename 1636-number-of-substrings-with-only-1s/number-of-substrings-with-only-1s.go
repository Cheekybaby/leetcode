const MOD = 1e9+7
func numSub(s string) int {
    fmt.Print(len(s))
    ans := 0
    for i := 0; i < len(s); {
        if s[i] == '1' {
            j := i
            for j < len(s) && s[j] == '1' {
                j++
            }
            n := j - i
            substrings := (n * (n + 1) / 2) % MOD
            ans += substrings
            i = j
        } else {
            i++
        }
    }

    return (ans % MOD)
}