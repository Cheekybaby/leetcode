class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 0;
        for (int i=0; i<nums.size(); i+=1){
            if (nums[i] == 0) return 0;
            if (nums[i]<0) neg+=1;
        }


        if (neg%2 == 0){
            return 1;
        }
        return -1;
    }
};