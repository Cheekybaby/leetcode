class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        for(int i=0; i<graph.size(); i+=1){
            if (color[i] == -1){
                if (!solve(graph, color, i, 0)) return false;
            }
        }
        return true;
    }
private:
    bool solve(vector<vector<int>> &graph, vector<int> &color, int index, int c){
        color[index] = c;
        for(auto &it:graph[index]){
            if (color[it] == -1){
                if (!solve(graph, color, it, 1-c)) return false;
            } else {
                if (it != index && color[it] == c) return false;
            }
        }
        return true;
    }
};