/*
- What can I understand after looking at the problem statement and the test cases
    1. We have two different sorted arrays.
    2. We need to find the median for both of them combined.
    3. That is, I need to merge both of the arrays in the sorted order and then 
        I need to find the median for each of them.
    4. The time complexity for this approach is O(n+m).


- The question is do I really need to merge them?
    - How can I get away with it without merging them?
    - The required time complexity is O(log(m+n)): This might mean binary a search? Or maybe I need to divide the arrays into half everytime, like the merge sort?
    - Even then how do I know what is going to be the median?
    - The median might come from only one array. What to do in that case?

- Binary Search
    - Use binary search to partition the smaller of the two input arrays into two parts. But on what grounds?
    - Find the partition of the larger array such that the sum of elements on the left side of the partition in both the arrays is half of the total elements.
    - Check if the partition is valid by verifying if the largest number on the left side is smaller than the number on the right.
    - If the partition is valid, calculate and return the median.
*/


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if (n > m) return findMedianSortedArrays(nums2, nums1);

        int x = n + m;
        int left = (n+m+1)/2;
        int l = 0, r = n;

        while (l<=r){
            int mid1 = (l + r) / 2;
            int mid2 = left - mid1;

            int a = INT_MIN, b = INT_MIN, y = INT_MAX, z = INT_MAX;

            if (mid1 < n){
                y = nums1[mid1];
            }
            if (mid2 < m){
                z = nums2[mid2];
            }
            if (mid1-1 >= 0){
                a = nums1[mid1-1];
            }
            if (mid2-1 >= 0){
                b = nums2[mid2-1];
            }
            if (a <= z && b <= y){
                if (x%2 == 1){
                    return max(a, b);
                } else {
                    return ((double)(max(a, b) + min(y, z)))/2.0;
                }
            } else if (a > z){
                r = mid1 - 1;
            } else {
                l = mid1 + 1;
            }
        }
        return 0;
    }
};