class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n % 2 == 1)
            return false;

        stack<int> openBrackets, unlocked;

        for (int i = 0; i < n; i += 1) {
            if (locked[i] == '0') {
                unlocked.push(i);
            } else if (s[i] == '(') {
                openBrackets.push(i);
            } else if (s[i] == ')') {
                if (openBrackets.empty() == false) {
                    openBrackets.pop();
                } else if (unlocked.empty() == false) {
                    unlocked.pop();
                } else {
                    return false;
                }
            }
        }

        while (!openBrackets.empty() && !unlocked.empty() &&
               openBrackets.top() < unlocked.top()) {
            openBrackets.pop();
            unlocked.pop();
        }

        if (!openBrackets.empty())
            return false;
        return true;
    }
};