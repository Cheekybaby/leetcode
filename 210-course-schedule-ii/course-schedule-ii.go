func dfs(adj [][]int, root int, visited, inRecursion []bool) (order []int, hasLoop bool) {
    visited[root] = true
    inRecursion[root] = true

    for _, v := range adj[root] {
        if inRecursion[v] {
            return []int{}, true
        }
        if !visited[v] {
            val, loop := dfs(adj, v, visited, inRecursion)
            if loop { return []int{}, true }
            order = append(order, val...)
        }
    }
    order = append(order, root)

    inRecursion[root] = false
    return order, false
}

func findOrder(numCourses int, prerequisites [][]int) []int {
    adj := make([][]int, numCourses)
    for _, course := range prerequisites {
        u := course[1]
        v := course[0]

        adj[u] = append(adj[u], v)
    }

    visited, inRecursion := make([]bool, numCourses), make([]bool, numCourses)
    var finalOrder []int
    for i := range adj {
        if !visited[i] {
            order, hasLoop := dfs(adj, i, visited, inRecursion)
            
            if hasLoop {
                return order
            }
            
            finalOrder = append(finalOrder, order...)
        }
    }

    if len(finalOrder) != numCourses {
        return []int{}
    }
    reverse(finalOrder)

    return finalOrder
}

func reverse(nums []int) {
    i, j := 0, len(nums)-1
    for i < j {
        nums[i], nums[j] = nums[j], nums[i]
        i++
        j--
    }
}