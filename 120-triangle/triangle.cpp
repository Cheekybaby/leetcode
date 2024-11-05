class Solution {
public:
    int solve(vector<vector<int>> &triangle, int m, int n, vector<vector<int>> &memo){
        int r = triangle.size();
        int c = triangle[m].size();

        if (m >= r || n < 0 || n >= c) return 1000000;
        if (m == r-1) return triangle[m][n];
        if (memo[m][n] != -1) return memo[m][n];

        return memo[m][n] = triangle[m][n] + min(solve(triangle, m+1, n, memo), solve(triangle, m+1, n+1, memo));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int> (triangle.size(), -1));
        return solve(triangle, 0, 0, dp);
    }
};