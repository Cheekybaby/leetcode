/*
    Find all the possible paths we can take,
    - We can do BFS on this to find path.
    - But how we store all the possible paths?
*/
class Solution {
private:
    bool isConnected(string& s, string& t) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != t[i])
                cnt++;

            if (cnt > 1)
                return false;
        }

        return cnt == 1;
    }
    void reverse(vector<string>& v) {
        int i = 0, j = v.size() - 1;
        while (i < j) {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    bool bfs(unordered_map<string, vector<string>>& adj, string st, string end,
             unordered_map<string, vector<string>>& parent) {
        unordered_map<string, int> visited;
        visited[st] = 0;
        queue<string> q;
        q.push(st);

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            for (auto& v : adj[curr]) {
                if (!visited.count(v)) {
                    visited[v] = visited[curr] + 1;
                    parent[v].push_back(curr);
                    q.push(v);
                } else if (visited[v] == visited[curr]+1){
                    parent[v].push_back(curr);
                }
            }
        }
        return visited.count(end) > 0;
    }
    void dfs(unordered_map<string, vector<string>>& parent, string st,
             string end, vector<string>& path, set<vector<string>>& paths) {
        if (st == end) {
            vector<string> temp = path;
            temp.push_back(st);
            reverse(temp);
            paths.insert(temp);
            return;
        }

        path.push_back(st);
        for (auto& v : parent[st]) {
            dfs(parent, v, end, path, paths);
        }
        path.pop_back();
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        int n = wordList.size();

        unordered_map<string, vector<string>> adj;
        unordered_map<string, vector<string>> parent;
        for (int i = 0; i < n; i++) {
            if (isConnected(beginWord, wordList[i])) {
                adj[beginWord].push_back(wordList[i]);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && isConnected(wordList[i], wordList[j])) {
                    adj[wordList[i]].push_back(wordList[j]);
                }
            }
        }

        // Do BFS to get all the possible shortest path
        bool exists = bfs(adj, beginWord, endWord, parent);
        if (!exists)
            return {};
        // Now we do DFS to get every possible shortest path?
        vector<string> path;
        set<vector<string>> paths;
        dfs(parent, endWord, beginWord, path, paths);
        return vector<vector<string>>(paths.begin(), paths.end());
    }
};