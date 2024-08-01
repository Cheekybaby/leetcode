class Solution {
public:
    int solve(int n, vector<int> &memo){
        if (memo[n] != -1) return memo[n];
        if (n == 0 || n == 1) return 1;

        memo[n] = solve(n-1, memo) + solve(n-2, memo);
        return memo[n];
    }
    int climbStairs(int n) {
        vector<int> memo(46, -1);
        return solve(n, memo);
    }
};