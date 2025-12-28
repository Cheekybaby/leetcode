func minimumRounds(tasks []int) int {
	freq := map[int]int{}
	for _, task := range tasks {
		freq[task]++
	}
	rounds := 0
	for _, val := range freq {
		if val == 1 {
			return -1
		}
		
        if val % 3 == 0 {
            rounds += (val/3)
        } else if val % 3 == 2 {
            rounds += ((val/3) + 1)
        } else {
            rounds += 2
            val -= 4
            rounds += (val/3)
        }
	}

	return rounds
}