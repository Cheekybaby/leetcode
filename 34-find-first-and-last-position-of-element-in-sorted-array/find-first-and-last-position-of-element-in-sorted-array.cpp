class Solution {
public:

    int b_search(vector<int> &v, int x, bool first){
        int left = -1, right = v.size();
        int mid = midpoint(left, right);
        int i = -1;
            while (right-left>1){
                mid = midpoint(left, right);
                if (v[mid] > x){
                    right = mid;
                } else if (v[mid] < x){
                    left = mid;
                } else {
                    i = mid;
                    if (first){
                        right = mid;
                    } else {
                        left = mid;
                    }
                }
            }
        return i;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left = b_search(nums, target, true);
        if (left == -1){
            return {-1, -1};
        }
        int right = b_search(nums, target, false);

        return {left, right};
    }
};