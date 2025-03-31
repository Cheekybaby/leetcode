func isAnagram(s string, t string) bool {
    if len(s) != len(t) {
        return false;
    }

    // Sort both the strings
    sRunes, tRunes := []rune(s), []rune(t); // Slice of characters of string s and t
    // Now sorting
    sort.Slice(sRunes, func(i, j int) bool {
        return sRunes[i] < sRunes[j]
    })
    sort.Slice(tRunes, func(i, j int) bool {
        return tRunes[i] < tRunes[j];
    })
    // Comparing the sorted strings
    for i := range sRunes {
        if sRunes[i] != tRunes[i] {
            return false;
        }
    }

    return true;
}