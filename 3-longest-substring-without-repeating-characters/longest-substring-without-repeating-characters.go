func lengthOfLongestSubstring(s string) int {
	var freq [256]int
	for k := range freq {
		freq[k] = 0
	}

	i, j := 0, 0
	maxLen := 0

	for j = range s {
		c := s[j]
		val := freq[c]

		if val > 0 {
			// We will be resetting the window
			for i < j && val != 0 {
				freq[s[i]]--  // We remove the character on i from the map
				val = freq[c] // See the value of current character in the map
				i++           // Update the left pointer
			}
		}
		maxLen = max(maxLen, j-i+1)
		freq[c]++
	}

	return maxLen
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}