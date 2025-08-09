class Solution {
private:
    bool dfs(vector<vector<int>> &graph, vector<int> &color, int curr, int c){
        color[curr] = c;

        for(auto &v:graph[curr]){
            if (color[v] == color[curr]) return false;
            else if (color[v] == -1){
                int c_v = 1 - c;
                if (dfs(graph, color, v, c_v) == false) return false;
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
                if (dfs(graph, color, i, 1) == false) return false;
            }
        }

        return true;
    }
};