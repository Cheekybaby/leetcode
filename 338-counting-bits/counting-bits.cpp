class Solution {
public:
    int countSetBits(int n){
        if (n == 0) return 0;

        return (n & 1) + countSetBits(n >> 1);
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for (int i=1; i<=n; i+=1){
            ans[i] = countSetBits(i);
        }
        return ans;
    }
};