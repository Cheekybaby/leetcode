func lengthOfLongestSubstring(s string) int {
    max_len := 0
    freq := map[byte]int{}
    j := 0
    for i := range s {
        char := s[i]
        freq[char]++

        win_len := i - j + 1

        for j < i && win_len > len(freq) {
            freq[s[j]]--

            if freq[s[j]] == 0 { delete(freq, s[j]) }

            j++
            win_len = i - j + 1
        }


        if win_len <= len(freq) {
            max_len = max(max_len, win_len)
        }
    }

    return max_len
}