class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.length();
        if (s2.length()< k){
            return false;
        }
        vector<int> window(26);
        vector<int> hashmapp(26);

        for (int i=0; i<k; i+=1){
            window[s2[i] - 'a']+=1;
            hashmapp[s1[i]-'a']+=1;
        }

        if (window == hashmapp){
            return true;
        }

        for (int i=k; i<s2.length(); i+=1){
            window[s2[i] - 'a']+=1;
            window[s2[i-k] - 'a']-=1;

            if (window == hashmapp){
                return true;
            }
        }

        return false;
    }
};