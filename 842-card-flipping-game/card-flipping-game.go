func flipgame(fronts []int, backs []int) int {
    set := make(map[int]bool)

    for i := range fronts {
        if fronts[i] == backs[i] {
            set[fronts[i]] = true
        }
    }

    if len(set) == len(fronts) {
        return 0
    }

    ans := 3000

    for i := range fronts {
        if _, ok := set[fronts[i]]; !ok {
            ans = min(ans, fronts[i])
        }
        if _, ok := set[backs[i]]; !ok {
            ans = min(ans, backs[i])
        }
    }

    if ans == 3000 {
        return 0
    }

    return ans
}