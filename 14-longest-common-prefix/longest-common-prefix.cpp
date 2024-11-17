class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pref = strs[0];
        for(int i=1; i<strs.size(); i+=1){
            string t = strs[i], temp;

            int n = min(t.length(), pref.length());
            for(int j=0; j<n; j+=1){
                if (t[j] != pref[j]){
                    break;
                }
                temp += t[j];
            }
            pref = temp;
        }

        return pref;
    }
};