func addSpaces(s string, spaces []int) string {
    spaced := []byte{}
    j := 0
    for i := range spaces {
        idx := spaces[i]
        for j < idx {
            spaced = append(spaced, s[j])
            j++
        }
        spaced = append(spaced, ' ')
    }

    for j < len(s) {
        spaced = append(spaced, s[j])
        j++
    }

    return string(spaced)
}