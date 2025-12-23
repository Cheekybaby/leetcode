func maxConsecutive(bottom int, top int, special []int) int {
    sort.Ints(special)
    max_consecutive := special[0] - bottom
    curr := special[0]
    for i := 1; i < len(special); i++ {
        next := special[i]
        diff := next - curr - 1
        max_consecutive = max(max_consecutive, diff)
        curr = next
    }
    diff := top - curr
    max_consecutive = max(max_consecutive, diff)

    return max_consecutive
}