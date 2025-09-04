func minCostClimbingStairs(cost []int) int {
    var first, second int

    first = cost[0]
    second = cost[1]

    for i := 2; i < len(cost); i++ {
        curr := cost[i] + min(first, second)
        first = second
        second = curr
    }

    return min(first, second)
}