func flowerGame(n int, m int) int64 {
    var odd1, odd2, even1, even2 int64
    
    if n % 2 == 0 {
        odd1 = int64(n/2)
        even1 = int64(n/2)
    } else {
        odd1 = int64(n/2 + 1)
        even1 = int64(n/2)
    }

    if m % 2 == 0 {
        odd2 = int64(m/2)
        even2 = int64(m/2)
    } else {
        odd2 = int64(m/2 + 1)
        even2 = int64(m/2)
    }

    return (odd1 * even2) + (odd2 * even1)
}