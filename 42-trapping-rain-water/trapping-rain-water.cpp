class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left(height.size()), right(height.size());
        int maxi = 0;
        for(int i=0; i<height.size(); i++){
            left[i] = max(maxi, height[i]);
            maxi = left[i];
        }
        maxi = 0;
        for(int i=height.size()-1; i>=0; i--){
            right[i] = max(maxi, height[i]);
            maxi = right[i];
        }
        int ans = 0;
        for(int i=0; i<height.size(); i++){
            ans += (min(left[i], right[i]) - height[i]);
        }
        
        return ans;
    }
};