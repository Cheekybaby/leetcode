// If we can check that if a string is palindrome or not in constant time, this can be 
// solved in O(n^2) time complexity.
// It is understandable that it'll require some space: O(n^2)
func longestPalindrome(s string) string {
    n := len(s)
    dp := make([][]int, n)
    for i:= range dp {
        dp[i] = make([]int, n)
    }
    len, idx := 1, 0
    // For length 1, all are palindrome
    for i:= range dp {
        dp[i][i] = 1
    }
    // For length 2
    for i:=0; i<n-1; i++ {
        if s[i] == s[i+1] {
            dp[i][i+1] = 1
            len = 2
            idx = i
        }
    }
    // For length 3 and above
    for k:=3; k<=n; k++ {
        for i:=0; i<=n-k; i++ {
            j:=i+k-1;
            if s[i] == s[j] && dp[i+1][j-1] != 0 {
                dp[i][j] = 1
                len = max(len, j-i+1)
                idx = i
            }
        }
    }

    return s[idx:(idx+len)]
}

func max(x, y int) int {
    if x >= y {
        return x
    }
    return y
}