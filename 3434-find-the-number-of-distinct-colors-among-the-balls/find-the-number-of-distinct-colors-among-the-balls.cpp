class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> balls;
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i=0; i<queries.size(); i++){
            int x = queries[i][0] - 1;
            int y = queries[i][1];
            if (balls.find(x) != balls.end()){
                m[balls[x]]--;
                if (m[balls[x]] == 0) m.erase(balls[x]);
            }
            balls[x] = y;
            m[y]++;

            ans.push_back(m.size());
        }

        return ans;
    }
};