class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        int a = 1, b = 1, result = a;
        for(int i=2; i<n; i+=1){
            result = a + b;
            a = b;
            b = result;
        }

        return result;
    }
};