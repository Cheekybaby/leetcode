/*
- Just use the target sum approach
*/

class Solution {
public:
    int solve(vector<int> &stones, int index, int val, vector<vector<int>> &memo){
        if (index == stones.size()){
            if (val < 0) return 1e9;
            return val;
        }
        if (memo[index][val+3000] != -1) return memo[index][val+3000];

        int takes = solve(stones, index + 1, val + stones[index], memo);
        int not_takes = solve(stones, index + 1, val - stones[index], memo);

        return memo[index][val+3000] = min(takes, not_takes);
    }
    int lastStoneWeightII(vector<int>& stones) {
        vector<vector<int>> memo(stones.size(), vector<int> (6001, -1));
        return solve(stones, 0, 0, memo);
    }
};