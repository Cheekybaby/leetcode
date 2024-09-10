class Solution {
public:
    int solve(int n, int m, string &text1, string &text2, vector<vector<int>> &memo){
        if (n == 0 || m == 0) return 0;
        if (memo[n][m] != -1) return memo[n][m];
        if (text1[n-1] == text2[m-1]){
            return memo[n][m] = 1 + solve(n-1, m-1, text1, text2, memo);
        } else {
            return memo[n][m] = max(solve(n-1, m, text1, text2, memo), solve(n, m-1, text1, text2, memo));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> memo(n+1, vector<int> (m+1, -1));
        return solve(n, m, text1, text2, memo);
    }
};