func isVowel(char byte) bool {
    if char == 'a' || char == 'e' || char == 'i' || char == 'o' || char == 'u' {
        return true
    }
    return false
}

func maxVowels(s string, k int) int {
    cnt := 0
    max_cnt := 0
    i, j := 0, 0
    for j < len(s) {
        char := s[j]
        if isVowel(char) {
            cnt++
        }

        for (j - i + 1) > k {
            if isVowel(s[i]) {
                cnt--
            }
            i++
        }

        if (j - i + 1) == k {
            max_cnt = max(max_cnt, cnt)
        }

        j++
    }
    return max_cnt
}