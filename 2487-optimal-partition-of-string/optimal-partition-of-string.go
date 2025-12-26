func partitionString(s string) int {
	cnt := 0
	for i := 0; i < len(s); {
		set := map[byte]bool{s[i]: true}
		j := i + 1
		for j < len(s) {
			if _, ok := set[s[j]]; ok {
				// here a substring ends
				cnt++
				break
			}
			set[s[j]] = true
			j++
		}
		// if _, ok := set[s[j]]; ok {
		// 	cnt++
		// }
		i = j
	}

	return cnt + 1
}