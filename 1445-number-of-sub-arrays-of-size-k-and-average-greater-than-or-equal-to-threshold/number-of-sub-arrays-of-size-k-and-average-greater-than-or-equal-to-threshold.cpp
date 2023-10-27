class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i=0, j=0;
        int ans = 0;
        int sum = 0;
        while (j<arr.size()){
            sum+=arr[j];
            if (j-i+1<k){
                j++;
            } else {
                int average = sum/k;
                if (average>=threshold){
                    ans++;
                }
                sum-=arr[i];
                i++;
                j++;
            }
        }

        return ans;
    }
};