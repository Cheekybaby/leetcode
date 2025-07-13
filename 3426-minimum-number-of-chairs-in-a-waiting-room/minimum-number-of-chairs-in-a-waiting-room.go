func minimumChairs(s string) int {
    ans, chair := 0, 0
    for i:=0; i<len(s); i++ {
        if (s[i] == 'E'){
            chair += 1
        } else {
            chair -= 1
        }

        ans = max(ans, chair)
    }
    return ans
}