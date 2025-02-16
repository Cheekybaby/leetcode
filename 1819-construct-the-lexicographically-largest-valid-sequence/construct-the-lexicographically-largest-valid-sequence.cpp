class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n-1, 0);
        vector<int> used(n+1, false);
        
        solve(0, ans, used, n);

        return ans;
    }

private:
    bool solve(int index, vector<int> &ans, vector<int> &used, int n) {
        if (index == ans.size()) return true;

        if(ans[index] != 0) {
            return solve(index+1, ans, used, n);
        }

        for(int i=n; i>=1; i--){
            if (used[i]) continue;
            used[i] = true;
            ans[index] = i;

            if (i == 1){
                if (solve(index+1, ans, used, n)) return true;
            } else if (index + i < ans.size() && ans[index+i] == 0) {
                ans[index+i] = i;

                if (solve(index+1, ans, used, n)) return true;

                ans[index+i] = 0;
            }

            ans[index] = 0;
            used[i] = false;
        }

        return false;
    }
};