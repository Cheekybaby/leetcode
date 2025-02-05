class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() == 0) return true;
        if(numCourses == 1) return !(prerequisites.size() == 1);
        vector<vector<int>> adj = createAdj(prerequisites, numCourses);
        int n = adj.size();
        vector<int> inDegree(n, 0);
        for(int i=0; i<n; i++){
            for(auto &it:adj[i]){
                inDegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> topo_order;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            topo_order.push_back(curr);

            for(auto &it:adj[curr]){
                if(--inDegree[it] == 0){
                    q.push(it);
                }
            }
        }

        return (n == topo_order.size());
    }

private:
    vector<vector<int>> createAdj(vector<vector<int>> &prerequisites, int n){
        vector<vector<int>> adj(n);
        int size = prerequisites.size();
        for(int i=0; i<size; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        return adj;
    }
};