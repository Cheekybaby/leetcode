class Solution {
public:
    int subarraycount(vector<int> &arr, int x){
        int i=0, j=0;
        int count = 0;
        unordered_map<int, int> mpp;
        while (j<arr.size()){
            mpp[arr[j]]++;

            while (i<=j && mpp.size()>x){
                if (--mpp[arr[i]] == 0){
                    mpp.erase(arr[i]);
                }
                i+=1;
            }
            count = count + (j-i+1);
            j+=1;
        }

        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraycount(nums, k) - subarraycount(nums, k-1);
    }
};