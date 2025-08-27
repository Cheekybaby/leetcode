class Solution {
private:
    vector<int> parent, rank;
    
    void Union(int u, int v){
        int parent_u = find(u);
        int parent_v = find(v);

        if (parent_u == parent_v) return ;

        if (rank[parent_u] > rank[parent_v]){
            parent[parent_v] = parent_u;
        } else if (rank[parent_u] < rank[parent_v]){
            parent[parent_u] = parent_v;
        } else {
            parent[parent_u] = parent_v;
            rank[parent_v]++;
        }
    }

    int find(int u){
        if (parent[u] == u) return u;

        return parent[u] = find(parent[u]);
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n); rank.resize(n);
        for(int i=0; i<n; i++) { parent[i] = i; rank[i] = 1; }
        
        for (auto ed:edges){
            int u = ed[0];
            int v = ed[1];

            int parent_u = find(u);
            int parent_v = find(v);

            if (parent_u != parent_v) Union(u, v);
        }
        
        // Run find once more to update the parent array
        for(int i=0; i<n; i++){
            find(i);
        }
        unordered_map<int,int> groups;
        for(int i=0; i<n; i++){
            groups[parent[i]]++;
        }

        // for(int i=0; i<n; i++) cout << parent[i] << " ";

        // Find all the valid pairs
        long long pairs = 0;
        long long sum = 0;
        for (auto &g:groups){
            long long val = g.second;
            pairs += (val * sum);
            sum += val;
        }

        return pairs;
    }
};