func maximumPoints(enemy []int, energy int) int64 {
    sort.Ints(enemy)
    if enemy[0] > energy {
        return 0
    }

    points := int64(0)
    total := int64(energy)
    for i := 1; i < len(enemy); i++ {
        total += int64(enemy[i])
    }

    points = total / int64(enemy[0])

    return points
}