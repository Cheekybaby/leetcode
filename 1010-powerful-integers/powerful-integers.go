func powerfulIntegers(x int, y int, bound int) []int {
    var ans []int
    set := map[int]bool{}

    if y == 1 {
        x, y = y, x
    }

    i := 1
    for i < bound {
        j := 1
        for j < bound {
            if i + j <= bound {
                if _, ok := set[i+j]; !ok {
                    set[i+j] = true
                    ans = append(ans, i + j)
                }
            }
            j *= y
            if y == 1 {
                break
            }
        }
        i *= x
        if x == 1 {
            break
        }
    }

    return ans
}