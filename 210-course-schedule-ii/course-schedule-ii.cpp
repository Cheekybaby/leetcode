class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);

        for(auto &it:prerequisites){
            adj[it[1]].push_back(it[0]);
            inDegree[it[0]]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if (inDegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto &x:adj[curr]){
                if(--inDegree[x] == 0){
                    q.push(x);
                }
            }
        }

        if(n == ans.size()){
            return ans;
        }
        return {};
    }
};