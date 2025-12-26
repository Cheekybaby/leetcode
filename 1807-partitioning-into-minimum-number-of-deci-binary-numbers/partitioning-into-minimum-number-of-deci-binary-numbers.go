func minPartitions(n string) int {
    var ans int
    for i := range n {
        digit := int(n[i]-'0')
        ans = max(ans, digit)
    }

    return ans
}