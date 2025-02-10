class Solution {
public:
    int solve(string &s, int i, int j, vector<vector<int>> &dp){
        if (i == j) return 1;
        if (i > j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j]){
           return dp[i][j] = 2 + solve(s, i+1, j-1, dp);
        }

        int left = solve(s, i+1, j, dp);
        int right = solve(s, i, j-1, dp);

        return dp[i][j] = max(left, right);
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(s, 0, n-1, dp);
    }
};