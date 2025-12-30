func executeInstructions(n int, startPos []int, s string) []int {
    ans := make([]int, len(s))
    for i := 0; i < len(s); i++ {
        x, y := startPos[0], startPos[1]
        step := 0
        for j := i; j < len(s); j++ {
            dir := s[j]
            x_next, y_next := x, y
            if dir == 'U' {
                x_next -= 1
            } else if dir == 'R' {
                y_next += 1
            } else if dir == 'D' {
                x_next += 1
            } else {
                y_next -= 1
            }

            if x_next >= 0 && x_next < n && y_next >= 0 && y_next < n {
                x, y = x_next, y_next
                step++
            } else {
                break
            }
        }
        ans[i] = step
    }

    return ans
}