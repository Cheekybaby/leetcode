func countSubstrings(s string) int {
    // A matrix of size n X n (n = len(s)) that stores if the substring 
    // from i to j is palindrom or not
    n := len(s)
    dp := make([][]bool, n+1)
    for i := range dp {
        dp[i] = make([]bool, n+1)
        for j := range dp[i] {
            dp[i][j] = false
        }
    }
    // length 1 is always a palindrome
    for i := 0; i <= n; i++ {
        dp[i][i] = true
    }

    // length 2 substrings
    for i := 1; i < n; i++ {
        if s[i] == s[i-1] {
            dp[i-1][i] = true
        }
    }

    // for length 3 and above
    for len := 3; len <= n; len++ {
        i, j := 0, len-1
        for j < n {
            if s[i] == s[j] && dp[i+1][j-1] {
                dp[i][j] = true
            }
            j++
            i++
        }
    }
    cnt := 0
    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            if dp[i][j] == true {
                cnt++
            }
        }
    }

    return cnt
}


// Generate All Substrings one by one
// Then check if each one of them is palindrome or not.
// We can save the smaller test cases to check for palindrome faster.