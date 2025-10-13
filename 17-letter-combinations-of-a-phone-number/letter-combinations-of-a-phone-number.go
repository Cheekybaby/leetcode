var keys = []string {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
func solve(digits string, idx int, comb []byte, poss_comb *[]string) {
    if idx == len(digits) {
        s := string(comb)
        *poss_comb = append(*poss_comb, s)
        return 
    }

    key := keys[(digits[idx] - '0')]
    for i := range key {
        comb = append(comb, key[i])
        solve(digits, idx+1, comb, poss_comb)
        comb = comb[:len(comb)-1]
    }

}

func letterCombinations(digits string) []string {
    if len(digits) == 0 {
        return []string{}
    }
    var ans []string
    var temp []byte
    solve(digits, 0, temp, &ans)
    return ans
}