func numTrees(n int) int {
    var ans float64 = 1
    for i := 1; i <= n; i++ {
        ans *= (float64(n + i) / float64(i))
        fmt.Println(ans)
    }

    num := int(math.Ceil(ans)) / (n + 1)

    return num
}