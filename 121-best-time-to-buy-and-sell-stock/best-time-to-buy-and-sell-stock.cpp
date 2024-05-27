class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0, j=1, profit = 0;
        while (j<prices.size()){
            if (prices[i]>prices[j]){
                i=j;
            } else {
                profit = max(profit, prices[j]-prices[i]);
            }
            j+=1;
        }
        return profit;
    }
};