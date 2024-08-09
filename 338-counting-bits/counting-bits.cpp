class Solution {
public:
    int bits(int n){
        if (n == 0) return 0;

        return (n & 1) + bits(n >> 1);
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for (int i=1; i<=n; i+=1){
            ans[i] = bits(i);
        }
        return ans;
    }
};