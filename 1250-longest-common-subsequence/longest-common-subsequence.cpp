class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(2, vector<int> (m+1));

        for (int i=0; i<=n; i+=1){
            bool curr = i & 1;
            for (int j=0; j<=m; j+=1){
                if (i == 0 || j == 0){
                    dp[curr][j] = 0;
                } else if (text1[i-1] == text2[j-1]){
                    dp[curr][j] = 1 + dp[1-curr][j-1];
                } else {
                    dp[curr][j] = max(dp[1-curr][j], dp[curr][j-1]);
                }
            }
        }

        return dp[n&1][m];
    }
};