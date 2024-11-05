class Solution {
public:
    int solve(vector<vector<int>> &matrix, int m, int n, vector<vector<int>> &memo){
        int s = matrix.size();

        if (m >= s || n < 0 || n >= s){
            return 10001;
        }
        if (m == s-1){
            return matrix[m][n];
        }
        if (memo[m][n] != -1) return memo[m][n];

        return memo[m][n] = matrix[m][n] + min(solve(matrix, m+1, n-1, memo), min(solve(matrix, m+1, n, memo), solve(matrix, m+1, n+1, memo)));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        /*
        1. Recursion and Memoization
        int ans = 100001;
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        for(int i=0; i<n; i+=1){
            ans = min(ans, solve(matrix, 0, i, dp));
        }
        return ans;
        
        2. Tabulation
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int i=0; i<n; i+=1){
            dp[0][i] = matrix[0][i];
        }

        for(int i=1; i<n; i+=1){
            for (int j=0; j<n; j+=1){
                int ldiag = (j>0) ? dp[i-1][j-1] : 100001;
                int up = dp[i-1][j];
                int rdiag = (j<n-1) ? dp[i-1][j+1] : 100001;

                dp[i][j] = matrix[i][j] + min(ldiag, min(up, rdiag));
            }
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end()); */

        // 3. Tabulation + Space Optimization
        vector<int> prev(n, 0);
        for(int i=0; i<n; i+=1){
            prev[i] = matrix[0][i];
        }
        vector<int> dp(n, 0);
        for(int i=1; i<n; i+=1){
            for(int j=0; j<n; j+=1){
                int ldiag = (j > 0) ? prev[j-1] : 100001;
                int up = prev[j];
                int rdiag = (j < n-1) ? prev[j+1] : 100001;

                dp[j] = matrix[i][j] + min(ldiag, min(up, rdiag));
            }
            prev = dp;
        }

        return *min_element(prev.begin(), prev.end());
    }
};