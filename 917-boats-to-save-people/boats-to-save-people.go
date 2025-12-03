func numRescueBoats(people []int, limit int) int {
    sort.Ints(people)
    boats := 0
    l, r := 0, len(people)-1

    for l <= r {
        sum := people[l] + people[r]

        if sum <= limit {
            boats++
            l++
            r--
        } else {
            boats++
            r--
        }
    }

    return boats
}