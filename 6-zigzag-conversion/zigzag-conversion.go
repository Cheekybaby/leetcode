func convert(s string, numRows int) string {
    n := len(s)
    if numRows == 1 || numRows >= n {
        return s
    }

    var zz string
    step := 2 * (numRows - 1)

    for i := 0; i < numRows; i++ {
        for j := i; j < n; j+=step {
            zz += string(s[j])

            diag := j + step - (2 * i)
            if i > 0 && i < numRows-1 && diag < n {
                zz += string(s[diag])
            }
        }
    }
    return zz
}