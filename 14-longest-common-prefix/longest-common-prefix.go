func longestCommonPrefix(strs []string) string {
    ans := strs[0]
    for i:=1; i<len(strs); i++ {
        // We check for the longest prefix in the current ans, and the current string
        ans = newPrefix(ans, strs[i])
    }

    return ans
}

func newPrefix(s, p string) string {
    var i int
    for i = 0; i < len(s) && i < len(p); i++ {
        if s[i] != p[i] {
            break
        }
    }
    return s[:i]
}