class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = m + n - 1;
        int i = m-1, j = n-1;
        while (pos >= 0){
            if (i < 0){
                nums1[pos] = nums2[j];
                j--;
                pos--;
                continue;
            }
            if (j < 0){
                nums1[pos] = nums1[i];
                i--;
                pos--;
                continue;
            }
            if (nums1[i] >= nums2[j]){
                nums1[pos] = nums1[i];
                i--;
            } else {
                nums1[pos] = nums2[j];
                j--;
            }
            pos--;
        }
    }
};