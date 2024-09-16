class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = INT_MIN;
        int currPrice = prices[0];

        for (int i=0; i<prices.size(); i+=1){
            if (prices[i] < currPrice){
                currPrice = prices[i];
            }
            int currProfit = prices[i] - currPrice;
            if (currProfit > maxProfit){
                maxProfit = currProfit;
            }
        }

        return maxProfit;
    }
};