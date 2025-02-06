class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp(n);
        for(int i=0; i<n; i++){
            dp[i] = matrix[0][i];
        }

        for(int i=1; i<n; i++){
            vector<int> row(n);
            for(int j=0; j<n; j++){
                int left = (j-1 >= 0) ? dp[j-1] : 100000;
                int up = dp[j];
                int right = (j+1 < n) ? dp[j+1] : 100000;

                row[j] = matrix[i][j] + min(left, min(up, right));
            }
            dp = row;
        }

        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            ans = min(ans, dp[i]);
        }

        return ans;
    }
};