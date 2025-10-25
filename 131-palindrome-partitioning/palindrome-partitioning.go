func solve(s string, idx int, temp []string, ans *[][]string) {
    if idx >= len(s) {
        // save the temp in the ans array
        tmp := make([]string, len(temp))
        copy(tmp, temp)
        *ans = append(*ans, tmp)

        return
    }

    for i := idx; i < len(s); i++ {
        if isPalindrome(s, idx, i) {
            temp = append(temp, s[idx:i+1])
            solve(s, i+1, temp, ans)
            temp = temp[:len(temp)-1]
        }
    }
}

func partition(s string) [][]string {
    var temp []string
    var ans [][]string
    solve(s, 0, temp, &ans)

    return ans
}

func isPalindrome(s string, st, end int) bool {
    for st < end {
        if s[st] != s[end] {
            return false
        }
        st++
        end--
    }

    return true
}