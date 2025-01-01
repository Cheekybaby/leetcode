class Solution {
public:
    int maxScore(string s) {
        int z = 0, o = 0;
        for(int i=0; i<s.length(); i+=1){
            if (s[i] == '0') z += 1;
            else o += 1;
        }
        int l = 0, r = o;
        int ans = 0;
        for(int i=0; i<s.length()-1; i+=1){
            if (s[i] == '0'){
                l += 1;
            } else {
                r -= 1;
            }
            ans = max(ans, l + r);
        }
        return ans;
    }
};