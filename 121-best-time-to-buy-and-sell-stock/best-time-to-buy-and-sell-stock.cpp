class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int ma = prices[prices.size()-1];
        for(int i = prices.size()-1; i>=0; i-=1){
            if (prices[i] >= ma){
                ma = prices[i];
            }

            profit = max(ma - prices[i], profit);
        }

        return profit;
    }
};