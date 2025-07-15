class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for(int i=1; i<strs.size(); i++){
            string s = strs[i];
            string temp;
            int n = min(s.length(), prefix.length());
            for(int j=0; j<n; j++){
                if (s[j] == prefix[j]) temp += s[j];
                else break;
            }
            prefix = temp;
        }

        return prefix;
    }
};