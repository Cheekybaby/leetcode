func maxIceCream(costs []int, coins int) int {
    max_ele := 0
    for _, cost := range costs {
        max_ele = max(max_ele, cost)
    }

    counts := make([]int, max_ele+1)

    for _, cost := range costs {
        counts[cost]++
    }

    fmt.Println(counts)

    ice_creams := 0
    for i := range counts {
        if counts[i] > 0 {
            gets := min(counts[i],  coins/i)
            ice_creams += gets
            coins -= (gets * i)
        }
    }

    return ice_creams
}