const MOD = 1e9+7

func valueAfterKSeconds(n int, k int) int {
    pref := make([]int, n)
    for i := range pref {
        pref[i] = 1
    }
    
    time := 1
    for time <= k {
        for i := 1; i < n; i++ {
            pref[i] = ((pref[i-1] % MOD) + (pref[i] % MOD)) % MOD
        }
        time++
    }

    return pref[n-1]
}