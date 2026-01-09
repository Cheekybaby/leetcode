func minFlips(target string) int {
    groups := 0
    ones := 0
    for i := 0; i < len(target); {
        if target[i] == '1' { ones++ }
        
        j := i
        for j < len(target) && target[j] == target[i] {
            j++
        }
        groups++
        i = j
    }

    if ones == 0 { return 0 }

    if target[0] == '0' { groups-- }

    return groups
}