func intToRoman(num int) string {
    var digits []int
    for num > 0 {
        digit := num % 10
        digits = append(digits, digit)
        num/=10
    }
    var roman string
    for i := len(digits)-1; i >= 0; i-- {
        if i == 3 {
            if digits[i] == 1 {
                roman += "M"
            } else if digits[i] == 2 {
                roman += "MM"
            } else {
                roman += "MMM"
            }
        } else if i == 2 {
            if digits[i] == 1 {
                roman += "C"
            } else if digits[i] == 2 {
                roman += "CC"
            } else if digits[i] == 3 {
                roman += "CCC"
            } else if digits[i] == 4 {
                roman += "CD"
            } else if digits[i] == 5 {
                roman += "D"
            } else if digits[i] == 6 {
                roman += "DC"
            } else if digits[i] == 7 {
                roman += "DCC"
            } else if digits[i] == 8 {
                roman += "DCCC"
            } else if digits[i] == 9 {
                roman += "CM"
            }
        } else if i == 1 {
            if digits[i] == 1 {
                roman += "X"
            } else if digits[i] == 2 {
                roman += "XX"
            } else if digits[i] == 3 {
                roman += "XXX"
            } else if digits[i] == 4 {
                roman += "XL"
            } else if digits[i] == 5 {
                roman += "L"
            } else if digits[i] == 6 {
                roman += "LX"
            } else if digits[i] == 7 {
                roman += "LXX"
            } else if digits[i] == 8 {
                roman += "LXXX"
            } else if digits[i] == 9 {
                roman += "XC"
            }
        } else {
            if digits[i] == 1 {
                roman += "I"
            } else if digits[i] == 2 {
                roman += "II"
            } else if digits[i] == 3 {
                roman += "III"
            } else if digits[i] == 4 {
                roman += "IV"
            } else if digits[i] == 5 {
                roman += "V"
            } else if digits[i] == 6 {
                roman += "VI"
            } else if digits[i] == 7 {
                roman += "VII"
            } else if digits[i] == 8 {
                roman += "VIII"
            } else if digits[i] == 9 {
                roman += "IX"
            }
        }
    }

    return roman
}