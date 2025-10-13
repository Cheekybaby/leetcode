func reverse(x int) int {
    flag := false
    if x < 0 {
        flag = true
        x *= -1
    }

    var rev []byte
    for x > 0 {
        digit := (byte(x % 10))
        rev = append(rev, digit)
        x /= 10
    }
    fmt.Println(rev)

    for i := range rev {
        x = x * 10 + int(rev[i])
    }

    if x < -2147483648 || x > 2147483647 {
        return 0
    }

    if flag {
        return x * -1
    }
    return x
}