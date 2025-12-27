func toBinString(num int) string {
    bin_string := make([]byte, 32)
    for i := 31; i >= 0; i-- {
        bin_string[i] = byte((num & 1) + int('0'))
        num >>= 1
    }

    for i := 0; i < 32; i++ {
        if bin_string[i] == '1' {
            return string(bin_string[i:])
        }
    }

    return string(bin_string)
}

func toInt(bin_string string) int {
    var num int
    x := 1
    for i := len(bin_string)-1; i >= 0; i-- {
        if bin_string[i] == '1' {
            num += x
        }
        x *= 2
    }

    return num
}

func allPossibilities(bin_string []string) []int {
    poss := make([]int, 6)

    poss[0] = toInt(bin_string[0] + bin_string[1] + bin_string[2])
    poss[1] = toInt(bin_string[0] + bin_string[2] + bin_string[1])

    poss[2] = toInt(bin_string[1] + bin_string[0] + bin_string[2])
    poss[3] = toInt(bin_string[1] + bin_string[2] + bin_string[0])

    poss[4] = toInt(bin_string[2] + bin_string[0] + bin_string[1])
    poss[5] = toInt(bin_string[2] + bin_string[1] + bin_string[0])

    return poss
}

func maxGoodNumber(nums []int) int {
    bin_string := make([]string, 3)
    for i := range nums {
        str := toBinString(nums[i])
        bin_string[i] = str
    }

    all_poss := allPossibilities(bin_string)

    ans := 0
    for _, num := range all_poss {
        if num > ans {
            ans = num
        }
    }

    return ans
}