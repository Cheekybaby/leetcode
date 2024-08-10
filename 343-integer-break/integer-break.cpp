/*
- We have an integer, which we need to break into k positive integers, where
k>=2
- We also need to maximize the product of those integers
- Return the maximum product we can obtain.

- We check for every possible integer from 1 to n-1 (since we need to have k>=2)
that sums upto the given number
- We need to make sure while we iterate i shouldn't take the value of n
- We subtract the number as we go down to 1
- At n == 1 we return 1
- At n < 1 we just return 0
- As we start coming back, we multiply the value we have at the given node to
the maximum of the products we get from the different branches from there.

*/
class Solution {
public:
    int solve(int n, int x, vector<int> &memo) {
        if (n == 0)
            return 1;
        if (memo[n] != -1) return memo[n];
        long long product = 1;
        for (int i = 1; i <= n; i += 1) {
            if (i != x) {
                long long sol = i * solve(n - i, x, memo);
                product = max(product, sol);
            }
        }
        
        return memo[n] = product;
    }
    int integerBreak(int n) {
        vector<int> memo(59, -1);
        return solve(n, n, memo);
    }
};