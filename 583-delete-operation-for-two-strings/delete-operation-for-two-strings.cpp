class Solution {
public:
    int solve(int n, int m, string &word1, string &word2, vector<vector<int>> &memo){
        if (n == 0 || m == 0) return 0;
        if (memo[n][m] != -1) return memo[n][m];

        if (word1[n-1] == word2[m-1]){
            return memo[n][m] = 1 + solve(n-1, m-1, word1, word2, memo);
        } else {
            return memo[n][m] = max(solve(n, m-1, word1, word2, memo), solve(n-1, m, word1, word2, memo));
        }
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length() + 1, vector<int> (word2.length() + 1, -1));
        int common = solve(word1.length(), word2.length(), word1, word2, dp);

        return (word1.length() + word2.length()) - (2 * common);
    }
};