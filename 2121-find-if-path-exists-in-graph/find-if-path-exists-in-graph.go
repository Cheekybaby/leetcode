func find(x int, parent []int) int {
    if x == parent[x] {
        return x
    }

    parent[x] = find(parent[x], parent)
    return parent[x]
}

func union(source, destination int, parent, rank []int) {
    source_p := find(source, parent)
    dest_p := find(destination, parent)

    if source_p == dest_p {
        return
    }

    if rank[source_p] > rank[dest_p] {
        parent[dest_p] = source_p
    } else if rank[source_p] < rank[dest_p] {
        parent[source_p] = dest_p
    } else {
        parent[source_p] = dest_p
        rank[dest_p]++
    }
}

func validPath(n int, edges [][]int, source int, destination int) bool {
    parent := make([]int, n)
    for i := range parent {
        parent[i] = i
    }
    rank := make([]int, n)

    for _, edge := range edges {
        u := edge[0]
        v := edge[1]

        union(u, v, parent, rank)
    }

    source_p := find(source, parent)
    dest_p := find(destination, parent)

    return (source_p == dest_p)
}