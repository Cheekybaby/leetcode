class Solution {
public:
    bool bfs(unordered_map<int, vector<int>>& adj,
             unordered_map<int, bool>& visited, int source, int destination) {
        queue<int> q;
        q.push(source);
        visited[source] = true;

        if (visited[destination] == true)
            return true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto& i : adj[u]) {
                if (visited[i] == false) {
                    visited[i] = true;
                    q.push(i);

                    if (visited[destination] == true)
                        return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int, bool> visited;
        return bfs(adj, visited, source, destination);
    }
};