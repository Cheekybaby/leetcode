/* Check if there is a cycle or not. If there is a cycle then we can't take all the courses
For DFS simply check for the cycle using recursion
For BFS cycle detection, use Kahn's algorithm to generate the topological sorting, if the sorting exists then there is no cycle.
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        unordered_map<int,vector<int>> adj;

        for(int i=0; i<pre.size(); i++){
            int u = pre[i][1];
            int v = pre[i][0];

            adj[u].push_back(v);
        }

        vector<bool> visited(numCourses, false);
        vector<int> indegree(numCourses, 0);

        for(int i=0; i<numCourses; i++){
            for(auto &v:adj[i]){
                indegree[v]++;
            }
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if (indegree[i] == 0) q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            int u = q.front();
            cnt+=1;
            q.pop();

            for(auto &v:adj[u]){
                indegree[v]--;

                if (indegree[v] == 0) q.push(v);
            }
        }

        if (cnt == numCourses) return true;
        return false;
    }
};