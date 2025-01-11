class Solution {
public:
    // int ones(int n){
    //     int cnt = 0;
    //     while(n > 0){
    //         if (n%2 == 1) cnt += 1;
    //         n/=2;
    //     }

    //     return cnt;
    // }
    int ones(int n, vector<int> &v){
        if (n == 0) return 0;
        if (v[n>>1] != -1) return (n&1) + v[n>>1];
        return ones(n>>1, v);
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1, -1);
        ans[0] = 0;
        for(int i=1; i<=n; i+=1){
            // ans[i] = __builtin_popcount(i); // Using builtin method
            // ans[i] = ones(i); O(nlogn)
            ans[i] = ones(i, ans);

        }
        return ans;
    }
};