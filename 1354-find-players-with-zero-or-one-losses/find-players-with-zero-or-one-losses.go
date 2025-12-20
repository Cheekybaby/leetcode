func findWinners(matches [][]int) [][]int {
    status := map[int][2]int{}
    for i := range matches {
        winner := matches[i][0]
        loser := matches[i][1]

        status[winner] = [2]int{status[winner][0] + 1, status[winner][1]}
        status[loser] = [2]int{status[loser][0], status[loser][1] + 1}
    }

    var lost, won []int
    for key, val := range status {
        if val[0] == 0 && val[1] == 0 {
            continue
        }
        if val[1] == 1 {
            lost = append(lost, key)
        }
        if val[1] == 0 {
            won = append(won, key)
        }
    }

    sort.Ints(won)
    sort.Ints(lost)

    return [][]int{won, lost}
}