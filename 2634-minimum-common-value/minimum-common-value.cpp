class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i=0, j=0;
        int ans = -1;
        while (i<nums1.size() && j<nums2.size()){
            if (nums1[i]>nums2[j]){
                j+=1;
            } else if (nums1[i] < nums2[j]){
                i+=1;
            } else {
                ans = nums1[i];
                break;
            }
        }

        return ans;
    }
};