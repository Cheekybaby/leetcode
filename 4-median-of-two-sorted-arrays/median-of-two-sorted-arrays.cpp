/*
- What can I understand after looking at the problem statement and the test cases
    1. We have two different sorted arrays.
    2. We need to find the median for both of them combined.
    3. That is, I need to merge both of the arrays in the sorted order and then 
        I need to find the median for each of them.

*/


class Solution {
public:
    vector<int> v;
    void merge(vector<int> &nums1, vector<int> &nums2){
        int i=0, j=0;
        while (i<nums1.size() && j < nums2.size()){
            if (nums1[i] <= nums2[j]){
                v.push_back(nums1[i]);
                i+=1;
            } else {
                v.push_back(nums2[j]);
                j+=1;
            }
        }

        while(i<nums1.size()){
            v.push_back(nums1[i]);
            i+=1;
        }
        while(j<nums2.size()){
            v.push_back(nums2[j]);
            j+=1;
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Merge the arrays
        double ans;
        merge(nums1, nums2);
        int n = v.size();
        if (n % 2 == 0){
            double a = (double)v[n/2];
            double b = (double)v[(n/2)-1];

            ans = (a + b)/2;
        } else {
            ans = (double)v[n/2];
        }

        return ans;
    }
};