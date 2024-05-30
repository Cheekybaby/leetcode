#include <string>
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mpp1;
        unordered_map<string, char> mpp2;
        int j = 0, i = 0;
        while (i < pattern.length() && j < s.length()) {
            char k = pattern[i];
            string t;
            while (s[j] != ' ' && j < s.length()) {
                t += s[j];
                j += 1;
            }

            if (mpp1.find(k)==mpp1.end()) mpp1[k] = t;
            if (mpp2.find(t)==mpp2.end()) mpp2[t] = k;

            if (mpp1[k] == t && mpp2[t] == k){
                i+=1;
                j+=1;
            } else {
                return false;
            }
        }

        if (j < s.length() || i < pattern.length())
            return false;
        return true;
    }
};