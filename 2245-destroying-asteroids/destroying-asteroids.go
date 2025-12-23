func asteroidsDestroyed(mass int, asteroids []int) bool {
    sort.Ints(asteroids)

    sum := mass
    for _, m := range asteroids {
        if sum >= m {
            sum += m
        } else {
            return false
        }
    }
    return true
}