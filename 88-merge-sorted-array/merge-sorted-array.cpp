class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i=0, j=0;
        while (i<m && j<n){
            if (nums1[i]<=nums2[j]) {
                ans.push_back(nums1[i]);
                i+=1;
            } else {
                ans.push_back(nums2[j]);
                j+=1;
            }
        }

        while (i<m){
            ans.push_back(nums1[i]);
            i+=1;
        }
        while (j<n){
            ans.push_back(nums2[j]);
            j+=1;
        }
        nums1.reserve(m+n);
        for (int l=0; l<ans.size(); l+=1){
            nums1[l] = ans[l];
        }
    }
};