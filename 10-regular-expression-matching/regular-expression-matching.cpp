class Solution {
private:
    vector<vector<int>> memo;

    bool solve(string& s, string& p, int i, int j) {
        if (j == p.length())
            return i == s.length();
        if (memo[i][j] != -1)
            return memo[i][j];

        bool firstMatch = (i < s.length() && (s[i] == p[j] || p[j] == '.'));

        if (j + 1 < p.length() && p[j + 1] == '*') {
            memo[i][j] = (solve(s, p, i, j + 2) ||
                          (firstMatch && solve(s, p, i + 1, j)));
        } else {
            memo[i][j] = (firstMatch && solve(s, p, i + 1, j + 1));
        }
        return memo[i][j];
    }

public:
    bool isMatch(string s, string p) {
        memo.assign(s.size() + 1, vector<int>(p.size() + 1, -1));
        return solve(s, p, 0, 0);
    }
};