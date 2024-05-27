class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i=0, j=0, ans = 0, sum = 0;
        while (j<arr.size()){
            sum+=arr[j];
            if (j-i+1 < k){
                j+=1;
            } else {
                if (sum/k >= threshold){
                    ans+=1;
                }
                sum-=arr[i];
                i+=1;
                j+=1;
            }
        }

        return ans;
    }
};