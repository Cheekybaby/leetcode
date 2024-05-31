class Solution {
public:
    bool palindrome(string s){
        int i=0, j=s.length()-1;
        while (i<=j){
            if (s[i]!=s[j]) return false;
            i+=1;
            j-=1;
        }

        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for (int i=0; i<words.size(); i+=1){
            string s = words[i];
            if (palindrome(s)) return s;
        }

        return "";
    }
};