class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int first = cost[0];
        int second = cost[1];
        int temp = 0;
        for(int i=2; i<n; i++){
            temp = second;
            second = cost[i] + min(first, second);
            first = temp;
        }

        return min(first, second);
    }
};