class Solution {
public:
    int solve(int a, int b, char c){
        if (c == '+') return a + b;
        if (c == '-') return a - b;
        if (c == '*') return a * b;

        return 0;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        bool isNum = true;
        for (int i=0; i<expression.length(); i+=1){
            if (!isdigit(expression[i])){
                isNum = false;
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1));

                for(auto a:left){
                    for(auto b:right){
                        ans.push_back(solve(a, b, expression[i]));
                    }
                }
            }
        }
        if(isNum) ans.push_back(stoi(expression));

        return ans;
    }
};