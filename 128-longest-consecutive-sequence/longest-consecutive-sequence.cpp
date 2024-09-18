/*
- We save whole array in an unordered set.
- We iterate through the unordered set finding the consecutive sequence.

- We count everytime we get a length.
- Return the maximum length found after the iteration ends.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for (auto it:st){
            if (!st.count(it-1)){
                int length = 1;
                while (st.count(it+length)){
                    length += 1;
                }
                ans = max(ans, length);
            }
        }

        return ans;
    }
};