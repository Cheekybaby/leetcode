class Solution {
private:
    bool isPalindrome(string s, int st, int end){
        while (st < end){
            if (s[st] != s[end]) return false;
            st++; end--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int i=0, j=s.length()-1;
        while (i < j){
            if (s[i] != s[j]){
                if (isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1)){
                    return true;
                }
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};