func numberOfBeams(bank []string) int {
    r_sum := 0
    tot_conn := 0
    for i := range bank {
        row := bank[i]
        sum := 0
        for j := range row {
            if row[j] == '1' {
                sum += 1
            }
        }
        conn := r_sum * sum
        tot_conn += conn
        if sum > 0 {
            r_sum = sum
        }
    }

    return tot_conn
}