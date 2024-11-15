class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1;
        int water = 0;
        while (i < j){
            water = max(water, min(height[i], height[j]) * (j-i));
            if (height[i] <= height[j]){
                i+=1;
            } else {
                j-=1;
            }
        }

        return water;
    }
};