class Solution {
public:
    bool solve(string &s, string &p, int i, int j, vector<vector<bool>> &memo){
        if (j == p.length()){
            return i == s.length();
        }

        if (memo[i][j] != false) return memo[i][j];

        bool firstMatch = (i < s.length() && (s[i] == p[j] || p[j] == '.'));

        if (j + 1 < p.length() && p[j+1] == '*'){
            return memo[i][j] = (solve(s, p, i, j+2, memo) || (firstMatch && solve(s, p, i+1, j, memo)));
        } else {
            return memo[i][j] = firstMatch && solve(s, p, i+1, j+1, memo);
        }
    }
    bool isMatch(string s, string p) {
        if (s == p) return true;
        vector<vector<bool>> dp(s.length()+1, vector<bool> (p.length()+1, false));
        return solve(s, p, 0, 0, dp);
    }
};