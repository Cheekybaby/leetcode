class Solution {
public:
    bool checkValidString(string s) {
        int left = 0, right = 0;
        for (char ch:s){
            if (ch == '('){
                left+=1;
                right+=1;
            } else if (ch == ')'){
                left-=1;
                right-=1;
            } else {
                left-=1;
                right+=1;
            }

            if (right<0) return false;
            if (left<0) left = 0;
        }

        return (left == 0);
    }
};