func isBalanced(freq []int) bool {
    f := 0
    for _, fr := range freq {
        if fr == 0 { continue }

        if f == 0 {
            f = fr
        } else if f != fr {
            return false
        }
    }
    return true
}
func longestBalanced(s string) int {
    max_len := 0
    for i := 0; i < len(s); i++ {
        freq := make([]int, 26)
        for j := i; j < len(s); j++ {
            char := s[j]
            freq[int(char - 'a')]++

            if isBalanced(freq) {
                max_len = max(max_len, j - i + 1)
            }
        }
    }
    return max_len
}