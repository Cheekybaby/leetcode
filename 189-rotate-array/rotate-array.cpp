class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        int i=0, j=nums.size()-1;
        while (i<=j){
            swap(nums[i], nums[j]);
            i+=1;
            j-=1;
        }

        i=0, j=k-1;
        while (i<=j){
            swap(nums[i], nums[j]);
            i+=1;
            j-=1;
        }
        i=k, j=nums.size()-1;
        while (i<=j){
            swap(nums[i], nums[j]);
            i+=1;
            j-=1;
        }
    }
};