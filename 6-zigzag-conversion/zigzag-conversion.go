func convert(s string, numRows int) string {
    if numRows == 1 || numRows > len(s) {
        return s
    }
    var ans string
    step := 2 * (numRows - 1)

    for i:=0; i<numRows; i++ {
        for j:=i; j<len(s); j+=step {
            ans += string(s[j])

            diag := j + step - 2 * i
            if i > 0 && i < numRows-1 && diag < len(s) {
                ans += string(s[diag])
            }
        }
    }

    return ans
}