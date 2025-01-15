class Solution {
public:
    int dp[501][501][3];
    int solve(vector<vector<int>>& coins, int n, int m, int k) {
        if (m == 0 && n == 0) {
            if (coins[n][m] < 0 && k > 0) {
                return 0;
            }
            return coins[n][m];
        }

        if (m < 0 || n < 0)
            return INT_MIN;

        if (dp[n][m][k] != INT_MIN)
            return dp[n][m][k];

        int not_take = INT_MIN, take = INT_MIN;
        take = coins[n][m] + max(solve(coins, n-1, m, k), solve(coins, n, m-1, k));
        if (k > 0 && coins[n][m] < 0){
            not_take = max(solve(coins, n-1, m, k-1), solve(coins, n, m-1, k-1));
        }

        return dp[n][m][k] = max(take, not_take);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();
        
        for(int i=0; i<501; i+=1){
            for(int j=0; j<501; j+=1){
                for(int k = 0; k<3; k+=1){
                    dp[i][j][k] = INT_MIN;
                }
            }
        }
        return solve(coins, n - 1, m - 1, 2);
    }
};