class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0, k=0;
        vector<int> nums(m+n);
        while (i<m && j<n){
            if (nums1[i]<=nums2[j]){
                nums[k] = nums1[i];
                k+=1;
                i+=1;
            } else if (nums1[i]>nums2[j]){
                nums[k] = nums2[j];
                k+=1;
                j+=1;
            }
        }

        while (i<m){
            nums[k] = nums1[i];
            i+=1;
            k+=1;
        }
        while (j<n){
            nums[k] = nums2[j];
            j+=1;
            k+=1;
        }

        for (int l=0; l<m+n; l+=1){
            nums1[l] = nums[l];
        }
    }
};