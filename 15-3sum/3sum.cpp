/*
- Sort the array
- Iterate through the array taking one element once and finding the other two in the rest of the array to the right.
- What are cases we need to avoid?
    - We need to make sure that we don't use up the same element more than once in a possible triplet.
    - For no possible duplicate triplets, we skip all the same elements we get while traversal.
    - One more way is to create a set of vector so that we don't get the redundancy. Otherwise, we can just skip the elements.

- Whenever we find a possible triplet we sort it in ascending order and then push it into the answer.
- 
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i=0; i<nums.size(); i+=1){
            if (i != 0 && nums[i] == nums[i-1]) continue; // Skipping the same element

            int j = i+1 , k = nums.size()-1;
            while (j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0){
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    ans.push_back(temp);

                    j+=1;
                    k-=1;

                    while (j<k && nums[j] == nums[j-1]) j+=1;
                    while (j<k && nums[k] == nums[k+1]) k-=1;
                } else if (sum > 0){
                    k-=1;
                } else {
                    j+=1;
                }
            }
        }

        return ans;
    }
};