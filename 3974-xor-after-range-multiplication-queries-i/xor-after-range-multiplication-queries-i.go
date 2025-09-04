const MOD = 1000000007
func xorAfterQueries(nums []int, queries [][]int) int {
    for i := range queries {
        query := queries[i]
        l, r, k, v := query[0], query[1], query[2], query[3]

        for i := l; i <= r; i += k {
            nums[i] = (nums[i] * v) % MOD
        }
    }

    var xor int
    for i := range nums {
        xor ^= nums[i]
    }
    return xor
}