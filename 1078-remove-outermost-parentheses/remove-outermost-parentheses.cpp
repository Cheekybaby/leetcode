class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<string> store;
        string temp;
        int open = 0, close = 0;
        for(int i=0; i<s.length(); i++){
            temp += s[i];
            if (s[i] == '(') open++;
            else if (s[i] == ')') close++;

            if (open - close == 0){
                store.push_back(temp);
                temp = "";
            }
        }

        string ans;
        for(auto &it:store){
            cout << solve(it) << " ";
            ans += solve(it);
        }
        return ans;
    }

private:
    string solve(string &s){
        return s.substr(1, s.length()-2);
    }
};