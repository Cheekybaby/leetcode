const mod = 1000000007
func baseUnitConversions(conversions [][]int) []int {
    n := len(conversions)+1
    adj := make([][][]int, n)

    for i := range conversions {
        conv := conversions[i]

        source := conv[0]
        target := conv[1]
        factor := conv[2]

        adj[source] = append(adj[source], []int{target, factor})
    }

    base := make([]int, n)
    base[0] = 1

    var queue []int
    queue = append(queue, 0)

    for len(queue) > 0 {
        node := queue[0]
        queue = queue[1:]

        for _, dest := range adj[node] {
            target := dest[0]
            factor := dest[1]

            base[target] = (base[node] * factor) % mod
            queue = append(queue, target)
        }
    }

    return base
}