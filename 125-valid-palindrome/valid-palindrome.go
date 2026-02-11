func isValidChar(char byte) (byte, bool) {
    if (char <= 'z' && char >= 'a') || (char <= '9' && char >= '0') {
        return char, true
    } else if char <= 'Z' && char >= 'A' {
        return (char + 32), true
    }
    return char, false
}

func isValidPalindrome(s []byte) bool {
    i, j := 0, len(s)-1
    for i < j {
        if s[i] != s[j] { return false }
        i++
        j--
    }
    return true
}

func isPalindrome(s string) bool {
    final_string := []byte{}
    for i := range s {
        if char, valid := isValidChar(s[i]); valid {
            final_string = append(final_string, char)
        }
    }

    return isValidPalindrome(final_string)
}