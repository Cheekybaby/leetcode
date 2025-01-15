class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = __builtin_popcount(num2);
        cout << cnt << endl;
        string ans = "00000000000000000000000000000000";
        string n = "00000000000000000000000000000000";
        
        stringyfy(num1, n);
 
        int i = 0;
        while(cnt > 0 && i < 32 - cnt){
            if (n[i] == '1'){
                ans[i] = '1';
                cnt -= 1;
            }
            i+=1;
        }
        cout << i << endl;
        while (i < 32 && cnt > 0){
            ans[i] = '1';
            i += 1;
            cnt -= 1;
        }

        cout << n << endl << ans << endl;
        long long x = stringToInt(ans);

        return x;
    }
private:
    void stringyfy(int n, string &s){
        for(int i=31; i>=0; i--){
            if (n % 2 == 1){
                s[i] = '1';
            }
            n /= 2;
        }
    }
    long long stringToInt(string &s){
        long long x = 0;
        for(int i=31; i>=0; i--){
            if (s[i] == '1'){
                x += pow(2, 31-i);
            }
        }

        return x;
    }
};