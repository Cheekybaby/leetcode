class Solution {
public:
    bool permutation(vector<int> &v){
        for (auto it:v){
            if (it!=0) return false;
        }

        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        vector<int> mapp(26, 0);
        for (int i=0; i<s1.length(); i+=1){
            mapp[s1[i]-'a']+=1;
        }

        int i=0, j=0;
        while (j<s2.length()){
            mapp[s2[j]-'a']-=1;
            if (j-i+1 == s1.length()){
                if (permutation(mapp)){
                    return true;
                }
                mapp[s2[i]-'a']+=1;
                i+=1;
            }
            j+=1;
        }

        return false;
    }
};