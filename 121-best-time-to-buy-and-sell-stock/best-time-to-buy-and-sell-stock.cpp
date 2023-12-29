class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0, j=0, pro=0;
        while (j<prices.size()){
            if (prices[j]<prices[i]){
                i=j;
            } else{
                pro = max(pro, prices[j]-prices[i]);
                j+=1;
            }
        }

        return pro;
    }
};