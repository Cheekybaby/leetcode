class Solution {
public:
    int solve(int n, vector<int> &memo){
        if (n <= 3) return n;
        if (memo[n] != -1) return memo[n];
        int ans = n;

        for (int i=1; i*i<=n; i+=1){
            ans = min(ans, 1+solve(n - i*i, memo));
        }
        memo[n] = ans;
        return memo[n];
    }
    int numSquares(int n) {
        vector<int> memo(n+1, -1);
        return solve(n, memo);
    }
};