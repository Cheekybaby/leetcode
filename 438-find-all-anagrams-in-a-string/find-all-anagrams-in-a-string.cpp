class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (p.length() > s.length()) return ans;
        vector<int> ph(26,0), window(26,0);
        for (int i=0; i<p.length(); i+=1){
            ph[p[i]-'a']+=1;
            window[s[i]-'a']+=1;
        }

        if (ph == window) ans.push_back(0);

        int i=0, j=p.length();
        while (j<s.length()){
            window[s[j]-'a']+=1;
            window[s[i]-'a']-=1;
            i+=1;
            if (window == ph) ans.push_back(i);
            j+=1;
        }

        return ans;
    }
};