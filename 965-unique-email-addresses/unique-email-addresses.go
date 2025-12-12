func processName(name string) string {
    var processed_name []rune
    for _, c := range name {
        if c == '.' {
            continue
        } else if c == '+' {
            break
        } else {
            processed_name = append(processed_name, c)
        }
    }
    return string(processed_name)
}
func numUniqueEmails(emails []string) int {
    unique_mail := map[string]bool{}

    for _, email := range emails {
        names := strings.SplitN(email, "@", 2)
        local_name := names[0]
        domain_name := names[1]

        local_name = processName(local_name)

        final_email := local_name + "@" + domain_name

        unique_mail[final_email] = true
    }

    return len(unique_mail)
}