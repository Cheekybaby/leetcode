func solve(ans *[]string, temp []byte, open, close, n int) {
    if open == n && close == n {
        brackets := string(temp)
        *ans = append(*ans, brackets)
        return 
    }

    if open < n {
        temp = append(temp, '(')
        solve(ans, temp, open+1, close, n)
        temp = temp[:len(temp)-1]
    }
    if close < open {
        temp = append(temp, ')')
        solve(ans, temp, open, close+1, n)
        temp = temp[:len(temp)-1]
    }
}

func generateParenthesis(n int) []string {
    var ans []string
    var temp []byte
    solve(&ans, temp, 0, 0, n)
    return ans
}