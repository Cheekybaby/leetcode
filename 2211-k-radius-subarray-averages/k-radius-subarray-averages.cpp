class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n,-1);
        if (k>n){
            return ans;
        } else if (k==0){
            return nums;
        }
        

        int i=0, j=0;
        long long sum=0;
        while (j<k){
            sum+=nums[j];
            j++;
        }
        int win = (2*k)+1;
        while (j<n){
            sum+=nums[j];
            if (j-i+1<win){
                j++;
            } else if (j-i+1==win){
                int average = sum/win;
                ans[i+k] = average;
                sum-=nums[i];
                i++;
                j++;
            }
        }
        return ans;
    }
};