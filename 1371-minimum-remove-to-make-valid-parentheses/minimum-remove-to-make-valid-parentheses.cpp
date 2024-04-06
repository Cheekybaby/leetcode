class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int left = 0, right = 0, p = 0;
        for (int i=0; i<s.length(); i+=1){
            if (s[i] == '('){
                left+=1;
                p+=1;
            } else if (s[i] == ')' && p>0){
                right+=1;
                p-=1;
            }
        }
        left = min(left, right);
        right = left;
        string ans = "";

        for (char ch:s){
            if (ch == '('){
                if (left > 0){
                    ans+=ch;
                    left-=1;
                }
            } else if (ch ==')'){
                if (right>0 && right>left){
                    ans+=ch;
                    right-=1;
                }
            } else {
                ans+=ch;
            }
        }

        return ans;
    }
};