func maximumPoints(enemy []int, energy int) int64 {
    min_energy := enemy[0]
    min_idx := 0
    for i, e := range enemy {
        if e < min_energy {
            min_energy = e
            min_idx = i
        }
    }

    if min_energy > energy {
        return 0
    }

    points := int64(0)
    total := int64(energy)
    for i := 0; i < len(enemy); i++ {
        if i == min_idx {
            continue
        }
        total += int64(enemy[i])
    }

    points = total / int64(min_energy)

    return points
}