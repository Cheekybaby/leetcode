func waysToBuyPensPencils(total int, cost1 int, cost2 int) int64 {
    var ways int64
    max1 := total / cost1

    for i := 0; i <= max1; i++ {
        left := total - (cost1 * i)
        
        max2 := left / cost2

        ways += int64(max2 + 1)
    }

    return ways
}