class Solution {
public:
    int minimumChairs(string s) {
        int chair = 0;
        int ans = 0;
        for(int i=0; i<s.length(); i++){
            if (s[i] == 'E') chair+=1;
            else chair-=1;

            ans = max(ans, chair);
        }
        return ans;
    }
};