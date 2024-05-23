class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;

        for (auto it:strs){
            string w = it;
            sort(w.begin(), w.end());
            mpp[w].push_back(it);
        }

        vector<vector<string>> ans;
        for (auto it:mpp){
            ans.push_back(it.second);
        }

        return ans;
    }
};