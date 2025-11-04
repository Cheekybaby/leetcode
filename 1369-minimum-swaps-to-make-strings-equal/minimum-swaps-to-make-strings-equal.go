func minimumSwap(s1 string, s2 string) int {
    var xtoy, ytox int 
    for i := range s1 {
        if s1[i] == s2[i] {
            continue
        }
        if s1[i] == 'x' {
            xtoy++
        } else{
            ytox++
        }
    }

    if (xtoy + ytox) % 2 != 0 {
        return -1
    }

    swaps := 0

    swaps += (xtoy/2 + ytox/2)
    swaps += (xtoy%2 + ytox%2)

    return swaps
}