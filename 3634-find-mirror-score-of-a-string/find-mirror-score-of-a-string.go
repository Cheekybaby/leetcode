func calculateScore(s string) int64 {
	seen := map[int][]int{}
	var tot_score int64
	for i := range s {
		char := int(s[i] - 'a')
		mirr := 25 - char

		idxs, ok := seen[mirr]
		if ok && len(idxs) > 0 {
			n := len(idxs)

			j := idxs[n-1]

			idxs = idxs[:n-1]
			seen[mirr] = idxs

			score := int64(i - j)
			tot_score += score
		} else {
			seen[char] = append(seen[char], i)
		}
	}

	return tot_score
}