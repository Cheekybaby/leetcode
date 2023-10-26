class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0, j=0;
        double average=0, maxAvg=INT_MIN;

        while (j<nums.size()){
            double next = (double)nums[j]/k;
            average+=next;
            if (j-i+1<k){
                j++;
            } else if (j-i+1==k){
                maxAvg = max(average, maxAvg);
                double first = (double)nums[i]/k;
                average-=first;
                i++;
                j++;
            }
        }

        return maxAvg;
    }
};