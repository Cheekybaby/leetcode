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
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n); rank.resize(n);
        for(int i=0; i<n; i++) { parent[i] = i; rank[i] = 1; }

        int available_wires = connections.size();
        if (n-1 > available_wires) return -1;

        // Now we can simulate the DSU on the connections.
        int wires = 0;
        for (auto conn:connections){
            int u = conn[0];
            int v = conn[1];

            int parent_u = find(u);
            int parent_v = find(v);

            if (parent_u != parent_v) {
                wires++;
                Union(u, v);
            }
        }
        
        int wires_left = available_wires - wires;
        int computer_left = n - (wires+1);
        
        return min(wires_left, computer_left);
    }
};