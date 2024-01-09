class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0){
            return "";
        }
        string s = "";
        sort(strs.begin(), strs.end());
        string first = strs[0], last = strs[strs.size()-1];
        for (int i=0; i<min(first.length(), last.length()); i+=1){
            if (first[i]!=last[i]){
                return s;
            }
            s+=first[i];
        }

        return s;
    }
};