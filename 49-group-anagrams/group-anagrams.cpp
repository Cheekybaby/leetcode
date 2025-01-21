class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>, vector<string>> mpp;

        for(int i=0; i<strs.size(); i+=1){
            map<char,int> temp;
            for(auto &it:strs[i]){
                temp[it]++;
            }

            mpp[temp].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto &it:mpp){
            ans.push_back(it.second);
        }

        return ans;
    }
};