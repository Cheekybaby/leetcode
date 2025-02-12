class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int open = 0, st = 0;
        for(int i=0; i<s.length(); i++){
            if (s[i] == '(') open++;
            else open--;

            if (open == 0) {
                ans += s.substr(st+1, i-st-1);
                open = 0;
                st = i+1;
            }
        }

        return ans;
    }
};