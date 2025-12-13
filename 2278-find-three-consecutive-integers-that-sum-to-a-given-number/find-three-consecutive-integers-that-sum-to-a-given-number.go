func sumOfThree(num int64) []int64 {
    var ans []int64

    if num % 3 != 0 {
        return ans
    }

    y := num/3

    ans = []int64{y-1, y, y + 1}

    return ans
}