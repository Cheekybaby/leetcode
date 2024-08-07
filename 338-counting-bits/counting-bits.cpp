class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for (int i=1; i<=n; i+=1){
            ans[i] = __builtin_popcount(i);
        }
        return ans;
    }
};