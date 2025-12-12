func rearrangeArray(nums []int) []int {
    rearr := make([]int, len(nums))
    pos, neg := 0, 1
    for _, num := range nums {
        if num < 0 {
            rearr[neg] = num
            neg+=2
        } else {
            rearr[pos] = num
            pos+=2
        }
    }

    return rearr
}