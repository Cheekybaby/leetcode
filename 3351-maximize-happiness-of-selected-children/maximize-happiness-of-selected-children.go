func maximumHappinessSum(happiness []int, k int) int64 {
	sort.Slice(happiness, func(i, j int) bool {
		return happiness[i] > happiness[j]
	})

	var total_happy int64
	child := 0
	for i := 0; i < k; i++ {
		happy := happiness[i] - child

		if happy <= 0 {
			break
		}
		total_happy += int64(happy)
		child++
	}
	return total_happy
}