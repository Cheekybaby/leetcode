class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0;
        while (j < s.length()) {
            while (j<s.length() && s[j]!=' '){
                j+=1;
            }
            int k = j-1;
            while (i<=k){
                swap(s[i], s[k]);
                i+=1;
                k-=1;
            }
            i=j+1;
            j+=1;
        }

        return s;
    }
};