func countGoodSubstrings(s string) int {
    freq := make(map[byte]int)
    j, cnt := 0, 0
    for i:=0; i<len(s); i++ {
        length := i - j + 1
        freq[s[i]]++
        if length == 3 {
            if len(freq) == 3 {
                cnt += 1
            }
            freq[s[j]]--
            if freq[s[j]] == 0 {
                delete(freq, s[j])
            }
            j+=1
        }
    }
    return cnt
}