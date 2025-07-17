class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> max_win(nums.size()-k+1, 0);
        deque<int> dq;
        int i=0, j=0;
        while(j < nums.size()){
            while(!dq.empty() && nums[dq.back()] < nums[j]){
                dq.pop_back();
            }
            dq.push_back(j);

            if (i > dq.front()){
                dq.pop_front();
            }

            if (j+1 >= k){
                max_win[i] = nums[dq.front()];
                i++;
            }
            j++;
        }

        return max_win;
    }
};