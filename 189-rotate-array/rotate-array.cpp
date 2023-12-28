class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> hashhh(k);
        if (nums.size()==1){
            return ;
        }
        if (k>nums.size()){
            k%=nums.size();
        }
        for (int i=0; i<k; i+=1){
            hashhh[i] = nums[nums.size()-k + i];
        }
        int rest = nums.size()-k;
        for (int i=1; i<=rest; i+=1){
            nums[nums.size()-i] = nums[nums.size()-k-i];
        }

        for (int i=0; i<k; i+=1){
            nums[i] = hashhh[i];
        }
    }
};