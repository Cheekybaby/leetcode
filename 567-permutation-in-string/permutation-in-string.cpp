class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.length();
        if (s2.length() < k){
            return false;
        }
        vector<int> hashmpp(26,0);
        vector<int> window(26,0);

        for (int i=0; i<k; i++){
            hashmpp[s1[i]-'a']++;
            window[s2[i]-'a']++;
        }
        
        if (hashmpp == window){
            return true;
        }

        for (int i=k; i<s2.length(); i++){
            window[s2[i]-'a']++;
            window[s2[i-k]-'a']--;

            if (window == hashmpp){
                return true;
            }
        }

        return false;
    }
};