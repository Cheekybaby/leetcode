func lengthOfLongestSubstring(s string) int {
	n := len(s)
	max_len := 0
	i, j := 0, 0
	var freq [256]int
	for j < n {
		char := (s[j])
		val := freq[char]

		for i < j && val > 0 {
			ch := (s[i])
			freq[ch]--
			val = freq[char]
			i++
		}
		
        max_len = max(max_len, j-i+1)
        freq[char]++
		j++
	}

	return max_len
}