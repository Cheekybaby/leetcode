func minCostClimbingStairs(cost []int) int {
    n := len(cost)
    steps := make([]int, n+1)
    
    for i, num := range cost {
        steps[i] = num
    }

    for i := 2; i <= n; i++ {
        steps[i] += min(steps[i-1], steps[i-2])
    }

    return steps[n]
}