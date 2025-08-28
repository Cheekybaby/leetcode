func romanToInt(s string) int {
    ans := 0
    for i:=0; i<len(s); {
        char := s[i]

        if char == 'I' {
            if i < len(s)-1 && (s[i+1] == 'V' || s[i+1] == 'X') {
                if s[i+1] == 'V' {
                    ans += 4
                } else {
                    ans += 9
                }
                i++
            } else {
                ans += 1
            }
        } else if char == 'V' {
            ans += 5
        } else if char == 'X' {
            if i < len(s)-1 && (s[i+1] == 'L' || s[i+1] == 'C'){
                if s[i+1] == 'L' {
                    ans += 40
                } else {
                    ans += 90
                }
                i++
            } else {
                ans += 10
            }
        } else if char == 'L' {
            ans += 50
        } else if char == 'C' {
            if i < len(s) - 1 && (s[i+1] == 'D' || s[i+1] == 'M'){
                if s[i+1] == 'D' {
                    ans += 400
                } else {
                    ans += 900
                }
                i++
            } else {
                ans += 100
            }
        } else if char == 'D' {
            ans += 500
        } else if char == 'M' {
            ans += 1000
        }
        i++
    }
    return ans
}