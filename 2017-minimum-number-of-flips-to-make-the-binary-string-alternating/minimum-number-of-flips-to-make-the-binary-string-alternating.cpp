class Solution {
public:
    int minFlips(string s) {
        int size = s.length();
        s+=s;
        string a, b;
        for (int i=0; i<s.length(); i+=1){
            if (i%2 == 0){
                a+='0';
                b+='1';
            } else {
                a+='1';
                b+='0';
            }
        }

        int i=0, j=0;
        int diff1=0, diff2=0;
        int ans = size;
        while (j<s.length()){
            if (s[j]!=a[j]){
                diff1+=1;
            }
            if (s[j]!=b[j]){
                diff2+=1;
            }

            if (j-i+1 > size){
                if (a[i]!=s[i]){
                    diff1-=1;
                }
                if (b[i]!=s[i]){
                    diff2-=1;
                }
                i+=1;
            }

            if (j-i+1 == size){
                ans = min(ans, min(diff1, diff2));
            }
            j+=1;
        }

        return ans;
    }
};