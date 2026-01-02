func dfs(graph [][]int, u int, path[]int, paths *[][]int) {
    path = append(path, u)

    if u == len(graph)-1 {
        temp := make([]int, len(path))
        copy(temp, path)

        *paths = append(*paths, temp)

        return
    }

    for _, v := range graph[u] {
        dfs(graph, v, path, paths)
    }
}

func allPathsSourceTarget(graph [][]int) [][]int {
    path := []int{}
    paths := [][]int{}
    dfs(graph, 0, path, &paths)

    return paths
}