class Solution {
public:
    string longestPalindrome(string s) {
        int ans = 0;
        string longest;
        for (int i=0; i<s.length(); i+=1){
            string temp = "";
            for (int j=i; j<s.length(); j+=1){
                temp.push_back(s[j]);
                if(isPalindrome(temp)){
                    if (temp.length() > ans){
                        ans = temp.length();
                        longest = temp;
                    }
                }
            }
        }
        return longest;
    }
private:
    bool isPalindrome(string &s){
        int i = 0;
        int j = s.length()-1;

        while (i < j){
            if (s[i] != s[j]){
                return false;
            }
            i+=1;
            j-=1;
        }

        return true;
    }
};