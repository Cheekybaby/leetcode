class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length() + 1,
                               vector<int>(word2.length() + 1, -1));
        for (int i=0; i<=word1.length(); i+=1){
            for (int j=0; j<=word2.length(); j+=1){
                if (i == 0 || j == 0){
                    dp[i][j] = 0;
                } else if (word1[i-1] == word2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return (word1.length() + word2.length()) - (2 * dp[word1.length()][word2.length()]);
    }
};