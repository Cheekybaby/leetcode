class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> edge_freq;
        int maxi = 0;

        for (int r=0; r<wall.size(); r+=1){
            int edge = 0;
            for (int c = 0; c<wall[r].size()-1; c+=1){
                int curr_len = wall[r][c];
                edge = curr_len + edge;
                edge_freq[edge]++;
                maxi = max(edge_freq[edge], maxi);
            }
        }

        return wall.size() - maxi;
    }
};