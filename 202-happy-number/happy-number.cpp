class Solution {
private:
    int getNextNumber(int x){
        int next_number = 0;
        while(x > 0){
            next_number += pow(x%10, 2);
            x/=10;
        }
        return next_number;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        while(visited.find(n) == visited.end()){
            visited.insert(n);
            n = getNextNumber(n);

            if (n == 1) return true;
        }

        return false;
    }
};