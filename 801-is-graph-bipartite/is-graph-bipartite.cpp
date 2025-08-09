class Solution {
private:
    bool bfs(vector<vector<int>> &graph, vector<int> &color, int curr, int c){
        color[curr] = c;
        queue<int> q;
        q.push(curr);

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto &v:graph[u]){
                if (color[v] == color[u]) return false;
                else if (color[v] == -1){
                    color[v] = 1 - color[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i=0; i<n; i++){
            if (color[i] == -1){
                if (bfs(graph, color, i, 1) == false) return false;
            }
        }

        return true;
    }
};