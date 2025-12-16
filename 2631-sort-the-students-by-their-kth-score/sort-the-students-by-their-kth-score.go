func sortTheStudents(score [][]int, k int) [][]int {
    m := len(score)
    k_scores := make([][2]int, m)
    for i := 0; i < m; i++ {
        k_scores[i] = [2]int{score[i][k], i}
    }

    sort.Slice(k_scores, func (i, j int) bool {
        return k_scores[i][0] > k_scores[j][0]
    })

    sorted := make([][]int, m)

    for i := range k_scores {
        idx := k_scores[i][1]
        sorted[i] = score[idx]
    }

    return sorted
}