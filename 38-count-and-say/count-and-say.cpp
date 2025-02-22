class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        if (n == 2) return "11";
        string res;

        string s = countAndSay(n-1);

        for(int i=0; i<s.length(); i++){
            char c = s[i];
            int cnt = 0;
            while(i<s.length() && s[i] == c){
                cnt++;
                i++;
            }

            res += (to_string(cnt) + c);
            i--;
        }

        return res;
    }
};