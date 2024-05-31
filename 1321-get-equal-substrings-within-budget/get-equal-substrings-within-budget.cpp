class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i=0, j=0;
        int ans = 0;
        int sum = 0;
        while (j<s.length()){
            sum+=(abs(s[j]-t[j]));

            while (sum > maxCost){
                sum-=(abs(s[i]-t[i]));
                i+=1;
            }

            ans = max(ans, j-i+1);
            j+=1;
        }

        return ans;
    }
};