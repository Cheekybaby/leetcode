func possibilities(s string, idx int, poss *[]string) {
    if idx >= len(s) {
        return 
    }

    if s[idx] >= '0' && s[idx] <= '9' {
        possibilities(s, idx+1, poss)
    } else {
        if s[idx] >= 'a' && s[idx] <= 'z' {
            char := byte(int(s[idx]) - 32)
            
            temp := s[:idx] + string([]byte{char}) + s[idx+1:]
            *poss = append(*poss, temp)
            
            possibilities(temp, idx+1, poss)
        } else {
            char := byte(int(s[idx]) + 32)
            
            temp := s[:idx] + string([]byte{char}) + s[idx+1:]
            *poss = append(*poss, temp)
            
            possibilities(temp, idx+1, poss)
        }

        possibilities(s, idx+1, poss)
    }
}

func letterCasePermutation(s string) []string {
    var poss []string
    poss = append(poss, s)
    possibilities(s, 0, &poss)

    return poss
}