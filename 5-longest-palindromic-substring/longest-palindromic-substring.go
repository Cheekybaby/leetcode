func longestPalindrome(s string) string {
    if len(s) == 1 {
        return s
    }

    st, end := 0, 0
	for i := range s {
        len1 := expand(s, i, i)
        len2 := expand(s, i, i+1)

        max_len := max(len1, len2)

		if max_len > end - st {
            st = i - (max_len - 1)/2
            end = i + (max_len)/2
        }
	}

	return s[st:end+1]
}

func expand(s string, st, end int) int {
	l, r := st, end

	for l >= 0 && r < len(s) && s[l] == s[r] {
		l--
		r++
	}

    return r - l - 1
}