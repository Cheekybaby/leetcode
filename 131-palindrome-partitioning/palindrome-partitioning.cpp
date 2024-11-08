class Solution {
public:
    // Global
    vector<vector<string>> ans;
    vector<string> temp;

    void solve(string &s, int index){
        if (index >= s.length()) {
            ans.push_back(temp);
            return ;
        }

        for (int i=index; i<s.length(); i+=1){
            if (isPalindrome(s, index, i)){
                temp.push_back(s.substr(index, i-index+1));
                solve(s, i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        solve(s, 0);

        return ans;
    }

    bool isPalindrome(string &s, int st, int end){
        while (st <= end){
            if (s[st] != s[end]){
                return false;
            }
            st+=1;
            end-=1;
        }

        return true;
    }
};