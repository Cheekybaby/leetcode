/* Topological Sort baby
    For BFS, use Kahn's algorithm to create the topological sorted order
    For DFS, use a stack to store the topological sorted order

*/
class Solution {
public:
    bool dfs(unordered_map<int,vector<int>> &adj, vector<bool> &visited, vector<bool> &inRecursion, int u, stack<int> &st){
        visited[u] = true;
        inRecursion[u] = true;
        for(auto &v:adj[u]){
            if (visited[v] == false && dfs(adj, visited, inRecursion, v, st)){
                return true;
            } else if (inRecursion[v] == true) return true;
        }
        inRecursion[u] = false;
        st.push(u);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);
        stack<int> st;
        unordered_map<int,vector<int>> adj;
        for(int i=0; i<pre.size(); i++){
            int u = pre[i][1];
            int v = pre[i][0];

            adj[u].push_back(v);
        }

        for(int i=0; i<numCourses; i++){
            if (visited[i] == false){
                bool flag = dfs(adj, visited, inRecursion, i, st);

                if (flag == true) return {};
            }
        }

        vector<int> sorted;
        while(!st.empty()){
            sorted.push_back(st.top());
            st.pop();
        }

        return sorted;
    }
};