func score(cards []string, x byte) int {
    freq1, freq2 := make([]int, 26), make([]int, 26)
    first, second, both := 0, 0, 0 // Contains the count of three groups
    mff, mfs := 0, 0 // Contains the maximum freq of first and second group
    pairs := 0 // Total number of pairs that we can make

    for i := range cards {
        card := cards[i]

        if card[0] == x && card[1] == x {
            both++
        } else if card[0] == x {
            freq1[card[1]-'a']++
            mff = max(mff, freq1[card[1]-'a'])
            first++
        } else if card[1] == x {
            freq2[card[0]-'a']++
            mfs = max(mfs, freq2[card[0]-'a'])
            second++
        }
    }

    if mff > first - mff {
        pairs += (first - mff)
        first = mff - (first - mff)
    } else {
        pairs += first/2
        first = first % 2
    }

    if mfs > second - mfs {
        pairs += (second - mfs)
        second = mfs - (second - mfs)
    } else {
        pairs += second/2
        second = second % 2
    }

    used := min(first+second, both)
    both -= used
    pairs = min(pairs * 2, pairs + both / 2)
    pairs += used

    return pairs
}