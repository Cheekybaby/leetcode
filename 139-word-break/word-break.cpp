class Solution {
public:
    bool solve(string s, int index, vector<string> &words, vector<int> &dp){
        if (index < 0) return true;
        if (dp[index] != -1) return dp[index] == 1;

        for(auto w:words){
            int len = w.length();

            if(index - len + 1 < 0) continue;

            if(s.substr(index - len + 1, len) == w && solve(s, index - len, words, dp)){
                return dp[index] = 1;
            }
        }

        return dp[index] = 0;
    }
    bool wordBreak(string s, vector<string>& words) {
        vector<int> dp(s.length(), -1);
        return solve(s, s.length()-1, words, dp);
    }
};