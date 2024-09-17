class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i=1; i<intervals.size(); i+=1){
            int l = intervals[i][0], r = intervals[i][1];
            int left = ans.back()[0], right = ans.back()[1];

            if (left <= r && right >= l){
                ans.back()[0] = min(l, left);
                ans.back()[1] = max(r, right);
            } else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};