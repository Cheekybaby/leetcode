class Solution {
public:
    int solve(int n, vector<int> &memo){
        if (n == 0) return 1;
        if (n < 0) return 0;
        if (memo[n] != -1) return memo[n];
        
        memo[n] = solve(n-1, memo) + solve(n-2, memo);
        return memo[n];
    }
    int climbStairs(int n) {
        vector<int> memo(n+1, -1);
        return solve(n, memo);
    }
};