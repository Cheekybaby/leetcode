class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for (auto &it:st){
            if (!st.count(it-1)){
                int len = 1;
                while (st.count(it+len)){
                    len+=1;
                }
                ans = max(len, ans);
            }
        }

        return ans;
    }
};