class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n-1;
        int j = n-1;
        while (i>=0){
            while (s[i]==' '){
                i--;
                j--;
            }
            while (i>=0){
                if (s[i]!=' '){
                    i--;
                } else {
                    break;
                }
            }
            break;
        }
        return j-i;
    }
};