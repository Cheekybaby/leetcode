func numTeams(rating []int) int {
    cnt := 0
    for i := 1; i < len(rating)-1; i++ {
        less_left, great_right := 0, 0
        great_left, less_right := 0, 0

        for j := 0; j < i; j++ {
            if rating[j] < rating[i] {
                less_left++
            } else if rating[j] > rating[i] {
                great_left++
            }
        }
        for j := i + 1; j < len(rating); j++ {
            if rating[j] > rating[i] {
                great_right++
            } else if rating[j] < rating[i] {
                less_right++
            }
        }

        cnt += (less_left * great_right)
        cnt += (great_left * less_right)
    }

    return cnt
}