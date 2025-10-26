/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

func copyRandomList(head *Node) *Node {
    if head == nil {
        return head
    }
    mpp := make(map[*Node]*Node)

    newHead := &Node{head.Val, nil, nil}
    mpp[head] = newHead

    dummy := head

    for dummy != nil {
        if _, ok := mpp[dummy]; !ok {
            newNode := &Node{dummy.Val, nil, nil}

            mpp[dummy] = newNode
        }

        dummy = dummy.Next
    }

    for key, val := range mpp {
        node := val

        node.Next = mpp[key.Next]
        node.Random = mpp[key.Random]
    }

    return newHead
}