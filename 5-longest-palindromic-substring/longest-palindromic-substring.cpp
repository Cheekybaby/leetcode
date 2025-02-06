class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool> (n, false));
        
        // All length 1 substrings are palindromic
        
        int len = 1, st = 0;
        for(int i=0; i<n; i++){
            dp[i][i] = true;
        }

        // For length 2
        for(int i=0; i<n-1; i++){
            if(s[i] == s[i+1]){
                len = 2;
                st = i;
                dp[i][i+1] = true;
            }
        }
        for(int k=3; k<=n; k++){
            for(int i=0; i<n-k+1; i++){
                int j = i+k-1;
                if (s[i] == s[j] && dp[i+1][j-1]){
                    len = k;
                    st = i;
                    dp[i][j] = true;
                }
            }
        }


        return s.substr(st, len);
    }
};