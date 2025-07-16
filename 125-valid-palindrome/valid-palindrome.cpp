class Solution {
private:
    bool isAlpha(char t){
        if (t >= 'a' && t <= 'z') return true;
        if (t >= 'A' && t <= 'Z') return true;
        return false;
    }
    bool isNumeric(char t){
        if (t < '0' || t > '9') return false;
        return true;
    }
    void createString(string &s){
        string tmp;
        for(int i=0; i<s.length(); i++){
            if (isNumeric(s[i])) tmp += s[i];
            else if (isAlpha(s[i])) tmp += tolower(s[i]);
        }
        s = tmp;
    }
public:
    bool isPalindrome(string s) {
        createString(s);
        int i=0, j=s.length()-1;
        while(i < j){
            if (s[i] != s[j]) return false;

            i++; j--;
        }

        return true;
    }
};