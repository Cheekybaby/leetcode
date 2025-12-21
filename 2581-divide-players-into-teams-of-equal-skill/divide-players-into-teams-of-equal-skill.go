func dividePlayers(skill []int) int64 {
    var total_chemistry int64

    sort.Ints(skill)
    i, j := 0, len(skill)-1
    skill_sum := skill[i] + skill[j]
    for i < j {
        sum := skill[i] + skill[j]
        if sum != skill_sum {
            return -1
        }
        total_chemistry += int64(skill[i] * skill[j])
        i++
        j--
    }

    return total_chemistry
}