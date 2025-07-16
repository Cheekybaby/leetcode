class Solution {
public:
    int trap(vector<int>& height) {
        int i = 1, j = height.size()-2;
        int lmax = height[0], rmax = height[height.size()-1];
        int total_water = 0;
        while (i <= j){
            int water = 0;
            if (lmax >= rmax){
                water = max(0, rmax - height[j]);
                rmax = max(rmax, height[j]);
                j--;
            } else {
                water = max(0, lmax - height[i]);
                lmax = max(lmax, height[i]);
                i++;
            }
            total_water += water;
        }
        return total_water;
    }
};