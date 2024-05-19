class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int j = s.length()-1, i;

        while (s[j] == ' '){
            j-=1;
        }

        i = j;
        
        while(j>=0){
            if (s[j] == ' ') break;
            j-=1;
        }

        len = abs(j-i);
        return len;
    }
};