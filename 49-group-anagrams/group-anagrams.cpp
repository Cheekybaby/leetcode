class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> group;
        unordered_map<string, vector<string>> m;
        for(int i=0; i<strs.size(); i++){
            string x = strs[i];
            string temp = x;
            sort(temp.begin(), temp.end());

            m[temp].push_back(x);
        }

        for(auto &it:m){
            group.push_back(it.second);
        }

        return group;
    }
};