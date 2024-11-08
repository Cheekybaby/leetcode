class Solution {
public:
    int solve(int n, vector<int> &memo){
        if (n == 0 || n < 0) return 0;
        if (n == 1 || n == 2) return 1;
        if (memo[n] != -1) return memo[n];

        return memo[n] = solve(n-1, memo) + solve(n-2, memo) + solve(n-3, memo);
    }
    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};