func evalRPN(tokens []string) int {
    mp := map[string]func(int,int)int {
        "+" : func (a, b int) int { return a + b },
        "-" : func (a, b int) int { return b - a },
        "*" : func (a, b int) int { return a * b },
        "/" : func (a, b int) int { return b / a },
    }
    
    var st []int

    for i := range tokens {
        if _, ok := mp[tokens[i]]; ok {
            if len(st) > 0 {
                one, two := st[len(st)-1], st[len(st)-2]
                st = st[:len(st)-2]

                f := mp[tokens[i]]
                eval := f(one, two)

                st = append(st, eval)
            }
        } else {
            num, _ := strconv.Atoi(tokens[i])  
            st = append(st, num)
        }
        
        // fmt.Println(st)
    }


    return st[0]
}