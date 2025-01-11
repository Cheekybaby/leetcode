class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        for(int i=0; i<t.length(); i+=1){
            if (j < s.length() && t[i] == s[j]){
                j+=1;
            }
            if (j == s.length()) break;
        }

        if (j < s.length()) return false;
        return true;
    }
};