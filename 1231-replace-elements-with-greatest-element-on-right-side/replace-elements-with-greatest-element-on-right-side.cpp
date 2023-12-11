class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int temp, maxi = arr[n-1];
        for (int i=n-2; i>=0; i--){
            temp = arr[i];
            arr[i] = maxi;
            maxi = max(temp, arr[i]);
        }
        arr[n-1] = -1;
        return arr;
    }
};