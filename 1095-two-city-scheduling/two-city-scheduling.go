func twoCitySchedCost(costs [][]int) int {
    sort.Slice(costs, func (i, j int) bool {
        diffA := costs[i][0] - costs[j][0]
        diffB := costs[i][1] - costs[j][1]

        return diffA < diffB
    })
    cost := 0
    for i := 0; i < len(costs)/2; i++ {
        cost += costs[i][0]
    }
    for i := len(costs)/2; i < len(costs); i++ {
        cost += costs[i][1]
    }
    return cost
}