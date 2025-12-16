func minOperations(boxes string) []int {
    sum_idx, cnt := 0, 0
    ans := make([]int, len(boxes))
    for i := range boxes {
        ans[i] = (cnt * i) - (sum_idx)

        if boxes[i] == '1' {
            cnt++
            sum_idx += i
        }
    }
    sum_idx, cnt = 0, 0
    for i := len(boxes)-1; i >= 0; i-- {
        ans[i] += (sum_idx - (cnt * i))

        if boxes[i] == '1' {
            cnt++
            sum_idx += i
        }
    }

    return ans
}