class Solution {
public:
    bool anagram(vector<int> &v){
        for (auto it:v){
            if (it!=0) return false;
        }

        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> ph(26,0);

        for (int i=0; i<p.length(); i+=1){
            ph[p[i]-'a']+=1;
        }

        int i=0, j=0;
        vector<int> ans;
        while(j<s.length()){
            ph[s[j]-'a']-=1;
            if (j-i+1 == p.length()){
                if (anagram(ph)){
                    ans.push_back(i);
                }
                ph[s[i]-'a']+=1;
                i+=1;
            }
            j+=1;
        }

        return ans;
    }
};