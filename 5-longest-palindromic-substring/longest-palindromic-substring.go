func longestPalindrome(s string) string {
    if len(s) == 1 {
        return s
    }

    i:=0
    j:=i+1
    k:=i+2

    pal := string(s[0])

    for i<j && j<k && k<len(s)+1 {
        // Check for length 2
        if s[i] == s[j] {
            new_pal := s[i:j+1]
            if len(new_pal) > len(pal) {
                pal = new_pal
            }
            // Check for length greater than 2
            start := i-1
            end := j+1
            for start>=0 && end<len(s) {
                if s[start] == s[end] {
                    new_pal := s[start:end+1]
                    if len(new_pal) > len(pal) {
                        pal = new_pal
                    }

                    start--
                    end++
                } else {
                    break
                }
            }
        }
        // Check for length 3
        if i<k && k<len(s) && s[i] == s[k] {
            new_pal := s[i:k+1]
            if len(new_pal) > len(pal) {
                pal = new_pal
            }
            // Check for length > 3
            start := i-1
            end := k+1
            for start>=0 && end<len(s) {
                if s[start] == s[end] {
                    new_pal := s[start:end+1]
                    if len(new_pal) > len(pal) {
                        pal = new_pal
                    }
                } else {
                    break
                }

                start--
                end++
            }
        }

        if len(pal) == len(s) {
            return s
        }
        i++
        j++
        k++
    }

    return pal
}