class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mpp;
        for (char c:order) {
            mpp[c] = 0;
        }
        for (char c:s){
            if (mpp.find(c)!=mpp.end()){
                mpp[c]+=1;
            }
        }

        string ans;
        for  (char c:order){
            ans.append(mpp[c], c);
        }
        for(char c:s){
            if (mpp.find(c) == mpp.end()){
                ans.push_back(c);
            }
        }

        return ans;
    }
};