class Solution {
public:
    string countAndSay(int n) {
        vector<string> dp(n+1);

        dp[1] = "1";

        for(int i=2; i<=n; i++){
            string s = dp[i-1];
            string res;

            for(int j = 0; j<s.length(); j++){
                char c = s[j];
                int cnt = 0;

                while(j < s.length() && s[j] == c){
                    j++;
                    cnt++;
                }

                res += (to_string(cnt) + c);
                j--;
            }

            dp[i] = res;
        }

        return dp[n];
    }
};