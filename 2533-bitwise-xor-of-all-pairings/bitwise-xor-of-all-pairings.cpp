class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        int x = nums2[0];
        for(int i=1; i<m; i+=1){
            x ^= nums2[i];
        }
        cout << x << endl;
        int y = nums1[0];
        for(int i=1; i<n; i+=1){
            y ^= nums1[i];
        }
        cout << y << endl;

        if (n % 2 == 0) x = 0;
        if (m % 2 == 0) y = 0;
        return x ^ y;
    }
};