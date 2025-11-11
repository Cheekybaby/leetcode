func canChoose(groups [][]int, nums []int) bool {
    j := 0
    for i := 0; i < len(nums); {
        if nums[i] == groups[j][0] {
            // go through nums looking for this subarray
            subarray := groups[j]
            f, s := i, 0
            for f < len(nums) && s < len(subarray) {
                if nums[f] != subarray[s] {
                    break
                }
                f++
                s++
            }
            if s == len(subarray) {
                j++
                i = f-1
            }
        }
        i++
        if j == len(groups){
            return true
        }
    }

    return (j == len(groups))
}