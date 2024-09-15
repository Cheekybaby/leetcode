class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0], currProduct = 1;
        for (int i=0; i<nums.size(); i+=1){
            currProduct *= nums[i];
            maxProduct = max(currProduct, maxProduct);

            if (currProduct == 0){
                currProduct = 1;
            }
        }

        currProduct = 1;
        for (int i=nums.size()-1; i>=0; i-=1){
            currProduct *= nums[i];
            maxProduct = max(maxProduct, currProduct);

            if (currProduct == 0){
                currProduct = 1;
            }
        }

        return maxProduct;
    }
};