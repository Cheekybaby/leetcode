class Solution {
public:
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &memo){
        if (i < 0 || j < 0) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        if (s1[i] == s2[j])
            return memo[i][j] = 1 + solve(s1, s2, i-1, j-1, memo);
        else 
            return memo[i][j] = max(solve(s1, s2, i-1, j, memo), solve(s1, s2, i, j-1, memo));
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int> (text2.length(), -1));
        return solve(text1, text2, text1.length()-1, text2.length()-1, dp);
    }
};