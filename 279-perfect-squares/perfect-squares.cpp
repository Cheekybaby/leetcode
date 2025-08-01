class Solution {
public:
    int solve(int n, vector<int> &dp){
        if (n <= 3) return n;
        if (dp[n] != -1) return dp[n];
        int ans = n;
        for(int i=1; i*i <= n; i++){
            int way = 1 + solve(n-(i*i), dp);

            ans = min(way, ans);
        }

        return dp[n] = ans;
    }
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        int ans = solve(n, dp);
        return ans;
    }
};