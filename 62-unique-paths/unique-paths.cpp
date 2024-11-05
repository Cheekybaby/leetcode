class Solution {
public:
    int solve(int m, int n, vector<vector<int>> &memo){
        if (m == 0 && n == 0){
            return 1;
        }
        if (m < 0 || n < 0){
            return 0;
        }
        if (memo[m][n] != -1) return memo[m][n];


        return memo[m][n] = solve(m-1, n, memo) + solve(m, n-1, memo);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return solve(m-1, n-1, dp);
    }
};