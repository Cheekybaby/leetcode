/*
- To make it n*n we need to make the palindrome checking a constant time operation.
- We can build a matrix before hand that can tell us if a substring is palindrome or not in constant time.
- The matrix will be of boolean values and its rows and matrix will keep the record of the particular string being palindrome or not.

*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool> (n, false));

        // for maxlength = 1
        int maxlen = 1;
        int start = 0;
        for(int i=0; i<n; i+=1){
            dp[i][i] = true;
        }

        // for maxlength = 2
        for(int i=0; i<n-1; i+=1){
            if (s[i] == s[i+1]){
                start = i;
                dp[i][i+1] = true;
                maxlen = 2;
            }
        }

        // for maxlength >= 3
        for (int k=3; k<=n; k+=1){
            for (int i=0; i<n-k+1; i+=1){
                int j = i+k-1;

                if (dp[i+1][j-1] && s[i] == s[j]){
                    dp[i][j] = true;
                    if (k >= maxlen){
                        maxlen = k;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxlen);
    }
};