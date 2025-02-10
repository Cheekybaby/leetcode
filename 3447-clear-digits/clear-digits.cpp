class Solution {
public:
    string clearDigits(string s) {
        string ans;
        int cnt = 0;

        for(int i=s.length()-1; i>=0; i--){
            if (s[i] >= '0' && s[i] <= '9'){
                cnt+=1;
                continue;
            } else {
                if (cnt > 0){
                    cnt-=1;
                    continue;
                }
            }
            ans+=s[i];
        }

        reverse(ans);
        return ans;
    }

private:
    void reverse(string &s){
        int i = 0, j = s.length()-1;
        while(i < j){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++; j--;
        }
    }
};