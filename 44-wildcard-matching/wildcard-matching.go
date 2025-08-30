func isMatch(s string, p string) bool {
    i, j := 0, 0
    idx, match := -1, 0
    for i < len(s) {
        if j < len(p) && (s[i] == p[j] || p[j] == '?'){
            i++
            j++
        } else if j < len(p) && p[j] == '*' {
            idx = j // Saw the asterisk
            match = i // The idex where it matched
            j++ // Ignored and moved on
        } else if idx != -1 {
            i = match + 1
            j = idx + 1 
            match++
        } else {
            return false
        }
    }
    for j < len(p) && p[j] == '*' {
        j++
    }

    return j == len(p)
}