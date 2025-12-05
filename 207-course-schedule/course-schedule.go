// Simple DFS for cycle detection
func dfs(adj [][]int, visited []bool, inRecursion []bool, root int) bool {
    visited[root] = true
    inRecursion[root] = true
    for _, v := range adj[root] {
        if inRecursion[v] {
            return true
        }
        if !visited[v] && dfs(adj, visited, inRecursion, v) {
            return true
        }
    }
    inRecursion[root] = false
    return false
}

func canFinish(numCourses int, pre [][]int) bool {
    visited := make([]bool, numCourses)
    inRecursion := make([]bool, numCourses)
    adj := make([][]int, numCourses)

    for i := range pre {
        u := pre[i][1]
        v := pre[i][0]

        adj[u] = append(adj[u], v)
    }

    for i := range numCourses {
        if (visited[i] == false) && dfs(adj, visited, inRecursion, i) {
            return false
        }
    }

    return true
}