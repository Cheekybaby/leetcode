class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Sort for monotonocity
        sort(nums.begin(), nums.end());
        // Declare variables for storing ans and the difference
        int ans = 0;
        int diff = INT_MAX;

        // Loop through the vector to find the ans
        for(int i=0; i<nums.size(); i+=1){
            for(int j=i+1; j<nums.size(); j+=1){
                for(int k=j+1; k<nums.size(); k+=1){
                    int sum = nums[i] + nums[j] + nums[k];
                    // cout << sum << " ";
                    int dif = abs(sum-target);
                    // cout << dif << " ";
                    if (dif < diff){
                        ans = sum;
                        diff = dif;
                    }
                    // cout << diff << endl;
                }
            }
        }

        return ans;

    }
};