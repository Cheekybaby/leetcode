class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int k = p.length();
        if (k>s.length()){
            return {};
        }

        vector<int> phash(26, 0);
        vector<int> window(26, 0);

        for (int i=0; i<k; i++){
            phash[p[i]-'a']++;
            window[s[i]-'a']++;
        }

        if (phash == window){
            ans.push_back(0);
        }

        for (int i=k; i<s.length(); i++){
            window[s[i-k]-'a']--;
            window[s[i]-'a']++;

            if (phash == window){
                ans.push_back(i-k+1);
            }
        }

        return ans;
    }
};