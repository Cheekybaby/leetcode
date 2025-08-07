/* Topological Sort baby
    For BFS, use Kahn's algorithm to create the topological sorted order
    For DFS, use a stack to store the topological sorted order

*/
class Solution {
public:
    void reverse(vector<int> &r){
        int i=0, j=r.size()-1;
        while (i < j){
            swap(r[i], r[j]);
            i++; j--;
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int> indegree(numCourses, 0);
        vector<bool> visited(numCourses, false);

        unordered_map<int,vector<int>> adj;
        for(int i=0; i<pre.size(); i++){
            int u = pre[i][0];
            int v = pre[i][1];

            adj[u].push_back(v);
        }

        for(int i=0; i<numCourses; i++){
            for (auto &v:adj[i]){
                indegree[v]++;
            }
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if (indegree[i] == 0) q.push(i);
        }
        vector<int> sorted;
        int cnt = 0;
        while(!q.empty()){
            int u = q.front();
            cnt++;
            sorted.push_back(u);
            q.pop();

            for(auto &v:adj[u]){
                if (visited[v] == false){
                    indegree[v]--;
                    if (indegree[v] == 0) q.push(v);
                }
            }
        }

        if (cnt == numCourses){
            reverse(sorted);
            return sorted;
        }
        return {};
    }
};