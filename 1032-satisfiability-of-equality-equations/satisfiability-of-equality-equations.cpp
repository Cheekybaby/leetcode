class Solution {
private:
    vector<int> parent, rank;

    void Union(int u, int v){
        int u_parent = find(u);
        int v_parent = find(v);

        if (u_parent == v_parent) return ;

        if (rank[u_parent] > rank[v_parent]){
            parent[v_parent] = u_parent;
        } else if (rank[u_parent] < rank[v_parent]) {
            parent[u_parent] = v_parent;
        } else {
            parent[u_parent] = v_parent;
            rank[v_parent]++;
        }
    }
    int find(int u) {
        if (parent[u] == u) return u;

        return parent[u] = find(parent[u]);
    }
public:
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26); rank.resize(26);
        
        for (int i=0; i<26; i++) { parent[i] = i; rank[i] = 1; }

        for(auto s:equations){
            if (s[1] == '='){
                int u = s[0] - 'a';
                int v = s[3] - 'a';

                Union(u, v);
            }
        }

        for(auto s:equations){
            if (s[1] == '!'){
                int u = s[0] - 'a';
                int v = s[3] - 'a';

                int u_parent = find(u);
                int v_parent = find(v);

                if (u_parent == v_parent) return false;
            }
        }

        return true;
    }
};