func numOfPairs(nums []string, target string) int {
    pair := map[string][]int{}
    for i, num := range nums {
        pair[num] = append(pair[num], i)
    }
    cnt := 0
    for _, num := range nums {
        if len(num) > len(target) {
            continue
        }
        if target[:len(num)] == num {
            rem := target[len(num):]
            if val, ok := pair[rem]; ok {
                if num == rem {
                    // in this case i is present in val
                    cnt += len(val)-1
                } else {
                    cnt += len(val)
                }
            }
        }
    }

    return cnt
}