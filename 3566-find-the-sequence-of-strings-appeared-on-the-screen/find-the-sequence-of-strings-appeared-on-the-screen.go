func stringSequence(target string) []string {
    seq := []string{}
    for i := range target {
        char := target[i]
        last := ""
        if len(seq) > 0 {
            last = seq[len(seq)-1]
        }
        j := int('a')
        for ; j <= int(char); j++ {
            curr := last + string(byte(j))
            seq = append(seq, curr)
        }
    }

    return seq
}