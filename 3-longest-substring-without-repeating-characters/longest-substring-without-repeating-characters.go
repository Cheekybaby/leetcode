func lengthOfLongestSubstring(s string) int {
    mpp := make(map[rune]int)
    i, j := 0, 0
    ans := 0
    for j=0; j<len(s);  {
        char := rune(s[j])
        val, ok := mpp[char]
        if ok && val != j && val >= i {
            // Reset the sliding window
            mpp[char] = j
            i = val + 1
            j = i
        } else {
            ans = max(ans, j-i+1)
            mpp[char] = j
            j += 1
        }
    }

    return ans
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}