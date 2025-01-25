class Solution {
public:
    int lev(string &word1, string &word2, int i, int j, vector<vector<int>> &dp){
        if (i == word1.length()) return word2.length() - j;
        if (j == word2.length()) return word1.length() - i;
        if (dp[i][j] != -1) return dp[i][j];


        if (word1[i] == word2[j]){
            return lev(word1, word2, i+1, j+1, dp);
        }

        return dp[i][j] = 1 + min(lev(word1, word2, i+1, j, dp), min(lev(word1, word2, i, j+1, dp), lev(word1, word2, i+1, j+1, dp)));
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<vector<int>> dp(n, vector<int> (m, -1));
        return lev(word1, word2, 0, 0, dp);
    }
};