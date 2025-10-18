func getPart(path string, idx int) (string, int) {
    i := idx
    for idx < len(path) && path[idx] != '/' {
        idx++
    }

    return path[i:idx], idx
}

func simplifyPath(path string) string {
    var stack []string
    i := 0 
    for i < len(path) {
        if path[i] == '/' {
            i++
            continue
        }
        str, idx := getPart(path, i)
        if str == ".." {
            if len(stack) > 0 {
                stack = stack[:len(stack)-1]
            }
        } else if str != "." {
            stack = append(stack, str)
        }
        i = idx
    }

    var simple_path string
    for i := range stack {
        simple_path += ("/" + stack[i])
    }

    if len(simple_path) == 0 {
        simple_path += "/"
    }

    return simple_path
}