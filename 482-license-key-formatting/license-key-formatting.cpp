class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string t;
        for(int i=0; i<s.length(); i++){
            if (s[i] == '-') continue;
            t += s[i];
        }
        string ans;
        int rem = (int)t.length() % k;
        if (rem != 0){
            for(int j=0; j<rem; j++){
                ans += toupper(t[j]);
            }
        }
        int i = rem;
        cout << i << endl;
        while(i < t.length()){
            if (i != 0) ans += "-";
            for(int j=i; j<i+k; j++){
                ans += toupper(t[j]);
            }
            i+=k;
        }
        return ans;
    }
};