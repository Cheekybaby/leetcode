class Solution {
public:
    
    int solve(vector<vector<int>> &grid, int m, int n, vector<vector<int>> &dp){
        if (m == 0 && n == 0) return grid[m][n];
        if (m < 0 || n < 0) return 100000;
        
        if (dp[m][n] != -1) return dp[m][n];

        int left = grid[m][n] + solve(grid, m, n-1, dp);
        int up = grid[m][n] + solve(grid, m-1, n, dp);

        return dp[m][n] = min(left, up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solve(grid, m-1, n-1, dp);
    }
};