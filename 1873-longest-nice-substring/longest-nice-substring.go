func longestNiceSubstring(s string) string {
    var ans string
    for i:=0; i<len(s); i++ {
        low := make([]int, 26)
        up := make([]int, 26)
        
        for j:=i; j<len(s); j++ {
            c := s[j]
            if unicode.IsUpper(rune(c)) {
                up[c - 'A'] = 1
            } else {
                low[c - 'a'] = 1
            }

            if (j - i) < len(ans) {
                continue
            }

            valid := true
            for k:=0; k<26; k++ {
                if (up[k] ^ low[k]) != 0 {
                    valid = false
                    break
                }
            }
            if valid {
                ans = s[i:j+1]
            }
        }
    }
    return ans
}