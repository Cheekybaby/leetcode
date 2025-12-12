func buildArray(target []int, n int) []string {
    var ops []string
    j := 0
    for i := range n {
        needed := target[j]
        curr := i+1
        ops = append(ops, "Push")

        if curr != needed {
            ops = append(ops, "Pop")
        } else {
            j++
        }

        if j == len(target) {
            break
        }
    }

    return ops
}