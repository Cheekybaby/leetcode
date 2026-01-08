func prisonAfterNDays(cells []int, n int) []int {
    days := make([][]int, 15)
    days[0] = cells
    for i := 1; i < 15; i++ {
        temp := make([]int, len(cells))
        copy(temp, cells)

        for i := 1; i < 7; i++ {
            if temp[i-1] != temp[i+1] {
                cells[i] = 0
            } else {
                cells[i] = 1
            }
        }
        cells[0] = 0
        cells[7] = 0

        copy(temp, cells)
        days[i] = temp
    }

    return days[n % 14]
}