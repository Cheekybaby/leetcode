class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0, j=0;
        double maxavg = INT_MIN, sum = 0;
        while (j<nums.size()){
            sum+=nums[j];
            if (j-i+1 < k){
                j+=1;
            } else if(j-i+1 == k){
                double avg = sum/k;
                maxavg = max(maxavg, avg);
                j+=1;
                sum-=nums[i];
                i+=1;
            } else {
                while (j-i+1 > k){
                    sum-=nums[i];
                    i+=1;
                }
                if (j-i+1 == k){
                    double avg = sum/k;
                    maxavg = max(maxavg, avg);
                }

                j+=1;
            }
        }
        return maxavg;
    }
};