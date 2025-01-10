class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq(26);
        for(auto &it:words2){
            vector<int> f(26);
            string s = it;
            for(auto &i:s){
                f[i-'a']++;
            }

            for(int l=0; l<26; l+=1){
                freq[l] = max(freq[l], f[l]);
            }
        }
        vector<string> ans;

        for(auto &it:words1){
            vector<int> f(26);
            string s = it;
            for(auto &i:s){
                f[i-'a']++;
            }
            bool good = true;
            for(int l=0; l<26; l++){
                if (freq[l] != 0 && f[l] < freq[l]){
                    good = false;
                }
            }
            if (good == true){
                ans.push_back(it);
            }
        }



        return ans;
    }
};