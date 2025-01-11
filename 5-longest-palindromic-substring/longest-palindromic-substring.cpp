class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> vc(s.length(), vector<int>(s.length(), 0));
        int len = 1, start = 0;
        // Length 1 substring
        for (int i = 0; i < s.length(); i += 1) {
            vc[i][i] = 1;
        }

        // Length 2 substring
        for (int i = 0; i < s.length() - 1; i += 1) {
            if (s[i] == s[i + 1]) {
                start = i;
                len = 2;
                vc[i][i + 1] = 1;
            }
        }

        // Length > 2 substring
        for (int k = 3; k < s.length() + 1; k += 1) {
            for (int i = 0; i < s.length() - k + 1; i += 1) {
                int j = i + k - 1;
                if (s[i] == s[j] && vc[i + 1][j - 1]) {
                    vc[i][j] = 1;
                    len = max(len, k);
                    start = i;
                }
            }
        }
        return s.substr(start, len);
    }
};