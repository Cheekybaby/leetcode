class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l=0, r=arr.size()-k;
        while (l<r){
            int mid = l+(r-l)/2;
            if (x-arr[mid]>arr[mid+k]-x){
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        vector<int> ans;
        for (int i = l; i<l+k; i+=1){
            ans.push_back(arr[i]);
        }

        return ans;
    }
};