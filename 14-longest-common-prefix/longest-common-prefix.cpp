class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()){
            return "";
        }
        string pre = strs[0];

        for (auto s:strs){
            while(s.find(pre)!=0){
                pre = pre.substr(0, pre.length()-1);
            }
        }
        return pre;
    }
};