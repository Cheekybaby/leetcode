func numOfBurgers(tomatoSlices int, cheeseSlices int) []int {
    if tomatoSlices == 0 && cheeseSlices == 0 {
        return []int{0,0}
    }

    if (tomatoSlices & 1 == 1) || (cheeseSlices >= tomatoSlices) || (tomatoSlices == 0 || cheeseSlices == 0) {
        return []int{}
    }

    ans := []int{}

    max_jumbo, max_small := tomatoSlices / 4, tomatoSlices / 2
    jumbo, small := 0, max_small

    for jumbo <= max_jumbo && small >= 0 {
        cheese := jumbo + small

        if cheese == cheeseSlices {
            ans = []int{jumbo, small}
        }

        jumbo += 1
        small -= 2
    }

    return ans
}