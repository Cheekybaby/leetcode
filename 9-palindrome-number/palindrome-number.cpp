class Solution {
public:
    bool isPalindrome(int x) {
        string xs = to_string(x);
        int i=0, j=xs.size()-1;
        while (i<j){
            if (xs[i] != xs[j]){
                return false;
            }
            i+=1;
            j-=1;
        }

        return true;
    }
};