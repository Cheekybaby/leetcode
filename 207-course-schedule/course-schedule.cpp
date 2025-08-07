// Check if there is a cycle or not. If there is a cycle then we can't take all the courses
class Solution {
public:
    bool dfs(unordered_map<int,vector<int>> &adj, vector<bool> &visited, int u, vector<bool> &inRecursion){
        visited[u] = true;
        inRecursion[u] = true;
        for(auto &v:adj[u]){
            if (visited[v] == false){
                if (dfs(adj, visited, v, inRecursion)) return true;
            } else if (inRecursion[v] == true) return true;
        }
        inRecursion[u] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        unordered_map<int,vector<int>> adj;

        for(int i=0; i<pre.size(); i++){
            int u = pre[i][1];
            int v = pre[i][0];

            adj[u].push_back(v);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);
        for(int i=0; i<numCourses; i++){
            if (visited[i] == false && dfs(adj, visited, i, inRecursion)){
                return false;
            }
        }
        return true;
    }
};