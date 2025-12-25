func largestWordCount(messages []string, senders []string) string {
    count := map[string]int{}
    for i := range messages {
        message := messages[i]
        sender := senders[i]

        spaces := 0
        for j := range message {
            if message[j] == ' ' {
                spaces++
            }
        }

        count[sender] += (spaces + 1)
    }

    var ans string
    max_cnt := 0

    for s, cnt := range count {
        if cnt > max_cnt {
            ans = s
            max_cnt = cnt
        } else if cnt == max_cnt {
            if s > ans {
                ans = s
            }
        }
    }
    return ans
}