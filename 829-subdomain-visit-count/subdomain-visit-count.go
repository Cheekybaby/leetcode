func subdomainVisits(cpdomains []string) []string {
    visits := map[string]int{}

    for i := range cpdomains {
        input := strings.Split(cpdomains[i], " ")
        cnt, _ := strconv.Atoi(input[0])
        domain := strings.Split(input[1], ".")
        subdomain := ""
        for i := len(domain)-1; i >= 0; i-- {
            subdomain = domain[i] + "." + subdomain
            visits[subdomain[:len(subdomain)-1]] += cnt
        }
    }

    ans := []string{}
    for key, val := range visits {
        cnt := strconv.Itoa(val)
        str := cnt + " " + key
        ans = append(ans, str)
    }

    return ans
}