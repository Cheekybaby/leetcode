func totalSum(nums []int) int {
    sum := 0
    for i := range nums {
        sum += nums[i]
    }

    return sum
}

func canCompleteCircuit(gas []int, cost []int) int {
    if totalSum(gas) < totalSum(cost) {
        return -1
    }

    total, start := 0, 0
    for i := range gas {
        total = (total - cost[i] + gas[i])

        if total <= 0 {
            total = 0
            start = (i + 1) % len(cost)
        }
    }

    return start
}