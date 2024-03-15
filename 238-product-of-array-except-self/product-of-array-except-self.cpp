class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size, 0);
        int count = 0;
        for (int i=0; i<size; i+=1){
            if (nums[i] == 0){
                count+=1;
            }
            if (count>1){
                return ans;
            }
        }

        if (count == 1){
            int product = 1;
            for (int i=0; i<size; i+=1){
                if (nums[i] == 0){
                    continue;
                }
                product*=nums[i];
            }
            for (int i=0; i<size; i+=1){
                if (nums[i] == 0){
                    ans[i] = product;
                    break;
                }
            }
            return ans;
        }

        int product = 1;
        for (int i=0; i<size; i+=1){
            if (nums[i] == 0){
                continue;
            }
            product*=nums[i];
        }
        for (int i=0; i<size; i+=1){
            ans[i] = product/nums[i];
        }

        return ans;
    }
};