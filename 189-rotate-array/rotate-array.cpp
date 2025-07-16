class Solution {
private:
    void arrayReverse(vector<int> &nums, int l, int r){
        while (l < r){
            swap(nums[l], nums[r]);
            l++; r--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        arrayReverse(nums, 0, n-1);
        arrayReverse(nums, 0, k-1);
        arrayReverse(nums, k, n-1);
    }
};