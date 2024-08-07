class Solution {
public:
    int solve(string s, int index, vector<int> &memo){
        if (index > s.length()) return 0;
        if (index == s.length()) return 1;
        if (s[index] == '0') return 0;
        if (memo[index] != -1) return memo[index];

        int ways = solve(s, index + 1, memo);
        if (index < s.length() && (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6'))){
            ways += solve(s, index + 2, memo);
        }

        memo[index] = ways;
        return ways;
    }
    int numDecodings(string s) {
        vector<int> memo(s.length(), -1);
        return solve(s, 0, memo);
    }
};