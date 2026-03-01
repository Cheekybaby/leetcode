func longestPalindrome(s string) string {
    isPalindrome := make([][]bool, len(s))
    var ans string
    for i := range isPalindrome {
        isPalindrome[i] = make([]bool, len(s))
    }
    // Length 1 is always palindrome
    for i := range len(s) {
        isPalindrome[i][i] = true
        ans = s[i:i+1]
    }
    // Length 2
    for i := 0; i < len(s)-1; i++ {
        if s[i] == s[i+1] { 
            isPalindrome[i][i+1] = true
            isPalindrome[i+1][i] = true
            ans = s[i:i+2]
        }
    }
    // For length 3 and beyond
    for k := 3; k <= len(s); k++ {
        l, r := 0, k-1
        for r < len(s) {
            if s[l] == s[r] && isPalindrome[l+1][r-1] {
                isPalindrome[l][r] = true
                isPalindrome[r][l] = true

                ans = s[l:r+1]
            }

            l++
            r++
        }
    }

    // fmt.Println(isPalindrome)
    return ans
}