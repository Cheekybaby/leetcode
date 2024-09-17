class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = m + n - 1;
        int i = m-1, j = n-1;

        while (pos >= 0){
            if (i < 0){
                nums1[pos] = nums2[j];
                pos-=1;
                j-=1;
                continue;
            }
            if (j < 0){
                nums1[pos] = nums1[i];
                pos-=1;
                i-=1;
                continue;
            }
            if (nums1[i] >= nums2[j]){
                nums1[pos] = nums1[i];
                i-=1;
                pos-=1;
            } else {
                nums1[pos] = nums2[j];
                j-=1;
                pos-=1;
            }
        }
    }
};