func maximumPrimeDifference(nums []int) int {
    first_prime, last_prime := -1, -1

    for i := range nums {
        if isPrime(nums[i]) {
            if first_prime == -1 {
                first_prime = i
            } else {
                last_prime = i
            }
        }
    }

    if first_prime == -1 || last_prime == -1 {
        return 0
    }
    return last_prime - first_prime
}
func isPrime(x int) bool {
    if x == 1 {
        return false
    }
    if x == 2 {
        return true
    }
    for i := 2; i*i <= x; i++ {
        if x % i == 0 {
            return false
        }
    }
    return true
}