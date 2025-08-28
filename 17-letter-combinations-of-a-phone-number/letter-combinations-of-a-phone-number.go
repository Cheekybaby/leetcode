func solve(index int, digits string, temp []byte, ans *[]string, keys []string) {
    n := len(digits)

    if index == n {
        s := string(temp)
        *ans = append(*ans, s)
        return 
    }

    k := keys[(digits[index] - '0')]
    for i := range k {
        temp = append(temp, k[i])
        solve(index+1, digits, temp, ans, keys)
        temp = temp[:len(temp)-1]
    }
}

func letterCombinations(digits string) []string {
    if len(digits) == 0 {
        return []string{}
    }

    var temp []byte
    var ans []string
    keys := []string{ "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
    

    solve(0, digits, temp, &ans, keys)

    return ans
}