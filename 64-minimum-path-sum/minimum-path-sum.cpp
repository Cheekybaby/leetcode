class Solution {
public:
    int solve(vector<vector<int>> &grid, int n, int m, vector<vector<int>> &dp){
        if (n == 0 && m == 0){
            return grid[n][m];
        }

        if (n < 0 || m < 0) return 1000000;
        if (dp[n][m] != -1) return dp[n][m];

        return dp[n][m] = grid[n][m] + min(solve(grid, n-1, m, dp), solve(grid, n, m-1, dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(grid, n-1, m-1, dp);
    }
};