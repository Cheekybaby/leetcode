class Solution {
public:
    int solve(string s, int idx, vector<int> &memo){
        if (idx == s.length()) {
            return 1;
        }
        if (s[idx] == '0'){
            return 0;
        }
        if (memo[idx] != -1){
            return memo[idx];
        }

        int ways = solve(s, idx+1, memo);
        if (idx+1 < s.length() && ((s[idx] == '1') || (s[idx] == '2' &&  s[idx+1] <= '6'))){
            ways += solve(s, idx+2, memo);
        }
        memo[idx] = ways;
        return memo[idx];
    }
    int numDecodings(string s) {
        vector<int> memo(s.length(), -1);
        return solve(s, 0, memo);
    }
};