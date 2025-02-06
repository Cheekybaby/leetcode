class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        
        for(int i=0; i<n; i++){
            dp[0][i] = matrix[0][i];
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int left = (j-1 >= 0) ? dp[i-1][j-1] : 100000;
                int up = dp[i-1][j];
                int right = (j+1 < n) ? dp[i-1][j+1] : 100000;

                dp[i][j] = matrix[i][j] + min(left, min(up, right));
            }
        }

        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            ans = min(ans, dp[n-1][i]);
        }

        return ans;
    }
};