class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int left = 0, right = arr.size()-k;

        while (left < right){
            int mid = left + (right - left)/2;
            if (x - arr[mid] > arr[mid+k] - x){
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        for (int i=left; i<left + k; i+=1){
            ans.push_back(arr[i]);
        }

        return ans;
    }
};