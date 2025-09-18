/*
We use DFS to check if there is a cycle in the graph or not.
Here we use an extra boolean array inRecursion to check if the current node
is in Recursion or not. We need to do it because unlike undirected graph where
we were always sure about the bidirection, here we need to explicityly know
where we are going from the next node.
So, the inRecursion keeps track of all the nodes we have visited in one dfs,
and this helps us identify if we have already came across an already visited node.
*/

func dfs(adj [][]int, u int, visited []bool, inRecursion []bool) bool {
    visited[u] = true
    inRecursion[u] = true // This node is now a part of this dfs recursion
    for _, v := range adj[u] {
        if inRecursion[v] { // This simply means that we came back to some node we already processed.
            return true // We return true because now we will start cycling.
        }
        if !visited[v] { // If we haven't visited it yet, then do it
            if dfs(adj, v, visited, inRecursion) { // If this call returns true, from the above if condtion, we simply return true
                return true
            }
        }
    }
    inRecursion[u] = false // Now it's no more in the recursion
    return false
}

func canFinish(n int, pre [][]int) bool {
    adj := make([][]int, n) // The adjecency list
    for i := range pre {
        u := pre[i][1]
        v := pre[i][0]

        adj[u] = append(adj[u], v)
    }

    // Using DFS
    visited := make([]bool, n) // To keep track of all the nodes we visit
    inRecursion := make([]bool, n) // To keep track of the nodes we visit in each of our dfs
    for i := 0; i < n; i++ {
        if (!visited[i]){
            if dfs(adj, i, visited, inRecursion) {
                return false
            }
        }
    }
    return true
}