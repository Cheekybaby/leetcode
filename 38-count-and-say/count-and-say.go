func countAndSay(n int) string {
    if n == 1 {
        return "1"
    }
    if n == 2 {
        return "11"
    }

    var res string
    s := countAndSay(n-1)

    for i := 0; i < len(s); i++ {
        char := s[i]
        count := 0
        for i < len(s) && s[i] == char {
            count++
            i++
        }

        res += (toString(count) + string(char))
        i--
    }

    return res
}
func toString(n int) string {
    return strconv.Itoa(n)
}