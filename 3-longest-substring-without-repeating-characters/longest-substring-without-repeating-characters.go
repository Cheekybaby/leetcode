func lengthOfLongestSubstring(s string) int {
    seen := map[byte]int{}
    max_len := 0
    j := 0
    for i := range s {
        char := s[i]
        seen[char]++
        // if it's already seen, shrink the window
        if val, ok := seen[char]; ok {
            for val > 1 {
                // Now shrink it
                del := s[j]
                seen[del]--

                if v, ok := seen[del]; ok {
                    if v == 0 {
                        delete(seen, del)
                    }
                }

                val = 0
                if v, ok := seen[char]; ok {
                    val = v
                }

                j++
            }
        }
        // Now check the length for a valid window
        len := i - j + 1
        max_len = max(max_len, len)
    }


    return max_len
}