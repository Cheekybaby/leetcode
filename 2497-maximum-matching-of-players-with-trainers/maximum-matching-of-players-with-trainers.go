func matchPlayersAndTrainers(players []int, trainers []int) int {
	sort.Ints(players)
	sort.Ints(trainers)

	i, j := 0, 0
	p := 0
	for i < len(players) && j < len(trainers) {
		if trainers[j] >= players[i] {
			p++
			i++
		}
		j++
	}

	return p
}