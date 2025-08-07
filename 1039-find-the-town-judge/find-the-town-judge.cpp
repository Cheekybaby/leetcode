class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,vector<int>> adj;
        for(int i=0; i<trust.size(); i++){
            int u = trust[i][0];
            int v = trust[i][1];

            adj[u].push_back(v);
        }
        vector<int> indegree(n+1, 0);
        for(int i=1; i<=n; i++){
            for(auto &v:adj[i]){
                indegree[v]++;
            }
        }
        for(int i=1; i<=n; i++){
            int x = i;
            int y = indegree[i];

            if (adj[x].size() == 0 && y == n-1) return x;
        }

        return -1;
    }
};