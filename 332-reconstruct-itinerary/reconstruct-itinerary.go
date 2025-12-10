func findItinerary(tickets [][]string) []string {
    adj := make(map[string][]string)

    for i := range tickets {
        from := tickets[i][0]
        to := tickets[i][1]

        adj[from] = append(adj[from], to)
    }

    for _, val := range adj {
        sort.Strings(val)
    }

    var itenaries []string


    var st []string
    st = append(st, "JFK")

    for len(st) > 0 {
        curr_airport := st[len(st)-1]

        dest, ok := adj[curr_airport]
        if ok && len(dest) > 0 {
            st = append(st, dest[0])
            dest = dest[1:]
            adj[curr_airport] = dest
        } else {
            itenaries = append(itenaries, curr_airport)
            st = st[:len(st)-1]
        }
    }

    reverse(itenaries)

    return itenaries
}
func reverse(s []string) {
    i, j := 0, len(s)-1
    for i < j {
        s[i], s[j] = s[j], s[i]
        i++
        j--
    }
}