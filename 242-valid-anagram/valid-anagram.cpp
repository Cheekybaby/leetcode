class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mpp;
        for (int i=0; i<s.length(); i+=1){
            mpp[s[i]]+=1;
        }

        for (int i=0; i<t.length(); i+=1){
            mpp[t[i]]-=1;
        }

        for (auto it:mpp){
            if (it.second != 0) return false;
        }

        return true;
    }
};