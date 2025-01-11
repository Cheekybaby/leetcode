class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k) return false;
        vector<int> m(26);
        for(int i=0; i<s.length(); i++){
            m[s[i]-'a']++;
        }

        int odd = 0;
        for(auto &it:m){
            if (it != 0 && it & 1) odd += 1;
        }

        if (odd > k) return false;
        return true;
    }
};