class Solution {
public:
    void bfs(unordered_map<int,vector<int>> &adj, vector<bool> &visited, int u){
        queue<int> q;
        q.push(u);
        visited[u] = true;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto &v:adj[u]){
                if (visited[v] == false){
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int,vector<int>> adj;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if (isConnected[i][j] == 1){
                    int u = i;
                    int v = j;

                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }

        vector<bool> visited(n, false);

        // we do bfs on all the nodes
        int cnt = 0;
        for(int i=0; i<n; i++){
            if (visited[i] == false){
                bfs(adj, visited, i);
                cnt++;
            }
        }

        return cnt;
    }
};