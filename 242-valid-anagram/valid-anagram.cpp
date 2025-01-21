class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> h(26);
        for(int i=0; i<s.length(); i++){
            h[s[i] - 'a']++;
            h[t[i] - 'a']--;
        }
        for(auto &it:h){
            if (it != 0) return false;
        }
        return true;
    }
};