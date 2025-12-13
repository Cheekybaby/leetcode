var vowels = map[byte]bool {
    'a' : true,
    'e' : true,
    'i' : true,
    'o' : true,
    'u' : true,
}

func maxVowels(s string, k int) int {
    cnt := 0
    max_cnt := 0
    i, j := 0, 0
    for j < len(s) {
        char := s[j]
        if _, ok := vowels[char]; ok {
            cnt++
        }

        for (j - i + 1) > k {
            if _, ok := vowels[s[i]]; ok {
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