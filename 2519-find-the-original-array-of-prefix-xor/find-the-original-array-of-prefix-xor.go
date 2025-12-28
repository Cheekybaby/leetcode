func findArray(pref []int) []int {
    st := pref[0]
    for i := 1; i < len(pref); i++ {
        pref[i] ^= st
        st ^= pref[i]
    }

    return pref
}