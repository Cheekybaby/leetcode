class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int ma = 0;
        for(int i=prices.size()-1; i>=0; i-=1){
            if (prices[i] > ma){
                ma = prices[i];
                continue;
            }
            int p = ma - prices[i];
            profit += p;
            ma = prices[i];
        }

        return profit;
    }
};