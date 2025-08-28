func isValid(s string) bool {
    var stack []byte
    pair := map[byte]byte {
        '(' : ')',
        '{' : '}',
        '[' : ']',
    }

    for i := range s {
        bracket := s[i]

        if bracket == '(' || bracket == '{' || bracket == '[' {
            stack = append(stack, bracket) // Push into the stack
        } else {
            if len(stack) == 0 { // Check if the stack is empty
                return false
            }

            last := stack[len(stack)-1] // The top element of the stack
            if bracket == pair[last] {
                stack = stack[:len(stack)-1] // Pop from the stack
            } else {
                return false
            }
        }
    }

    return len(stack) == 0
}