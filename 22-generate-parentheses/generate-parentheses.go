func solve(n, open, close int, temp []byte, ans *[]string) {
    if open == n && close == n {
        s := string(temp)
        *ans = append(*ans, s)
        return
    }

    if open < n {
        temp = append(temp, '(')
        solve(n, open+1, close, temp, ans)
        temp = temp[:len(temp)-1]
    }

    if close < open {
        temp = append(temp, ')')
        solve(n, open, close+1, temp, ans)
        temp = temp[:len(temp)-1]
    }
}

func generateParenthesis(n int) []string {
    var ans []string
    var temp []byte
    solve(n, 0, 0, temp, &ans)
    return ans
}