class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = prices[0];
        for (int i=1; i<prices.size(); i+=1){
            int currPrice = prices[i];
            if (currPrice <= minPrice){
                minPrice = currPrice;
            }
            int currProfit = currPrice - minPrice;
            if (currProfit >= maxProfit){
                maxProfit = currProfit;
            }
        }

        return maxProfit;
    }
};