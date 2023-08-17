class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right=height.size()-1;
        int volume = 0;
        while(left<=right){
            int length = right-left;
            int breadth = min(height[left],height[right]);
            volume = max(volume, length*breadth);
            if(height[left]<=height[right]){
                left++;
            } else {
                right--;
            }
        }
        return volume;
    }
};