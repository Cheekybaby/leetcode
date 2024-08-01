class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i=1; i<prices.size(); i+=1){
            if(prices[i] < minPrice){
                minPrice = prices[i];
            }
            int currProfit = prices[i] - minPrice;
            if (currProfit > maxProfit){
                maxProfit = currProfit;
            }
        }

        return maxProfit;
    }
};