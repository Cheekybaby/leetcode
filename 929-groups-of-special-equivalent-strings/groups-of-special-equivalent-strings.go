func numSpecialEquivGroups(words []string) int {
    visited := make([]bool, len(words))
    groups := 0

    for i := 0; i < len(words); i++ {
        if visited[i] == true {
            continue
        }

        var odd, even []byte

        for idx := range words[i] {
            if idx % 2 == 0 {
                even = append(even, words[i][idx])
            } else {
                odd = append(odd, words[i][idx])
            }
        }

        sort.Slice(even, func(l, r int) bool {
            return even[l] < even[r]
        })
        sort.Slice(odd, func(l, r int) bool {
            return odd[l] < odd[r]
        })

        for j := i + 1; j < len(words); j++ {
            if visited[j] == true {
                continue
            }

            var curr_odd, curr_even []byte
            for idx := range words[j] {
                if idx % 2 == 0 {
                    curr_even = append(curr_even, words[j][idx])
                } else {
                    curr_odd = append(curr_odd, words[j][idx])
                }
            }

            sort.Slice(curr_even, func(l, r int) bool {
                return curr_even[l] < curr_even[r]
            })
            sort.Slice(curr_odd, func(l, r int) bool {
                return curr_odd[l] < curr_odd[r]
            })

            if compare(curr_odd, odd) && compare(curr_even, even) {
                visited[j] = true
            }
        }

        groups++
    }
    return groups
}
func compare(arr1, arr2 []byte) bool {
    for i := 0; i < len(arr1); i++ {
        if arr1[i] != arr2[i] {
            return false
        }
    }
    return true
}